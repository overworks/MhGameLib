#ifndef	_MH_STL_ATOMIC_HPP_
#define	_MH_STL_ATOMIC_HPP_

#include <mh/prerequisite.h>

namespace Mh
{
	// 이하는 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2047.html 에서 긁어온것
	// http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2195.html 와 boost의 atomic.hpp 를 참조할것

	// The expectation is that this will usually be implemented in terms of
	// low_level_atomics.h by checking whether the template argument has
	// sufficient size and alignment constraints that it can be safely
	// cast to a primitive integer type, and one of the low level primitives
	// can be applied.

	enum ordering_constraint {raw, acquire, release, ordered};
		// 비공식:
		// raw ==> This operation is unordered, and may become
		//          visible to other threads in an order that is
		//          constrained only by ordering constraints on other
		//          operations.
		// release ==> All prior memory operations (including ordinary
		//          assignments) become visible to a an acquire
		//          operation on the same object that sees the resulting
		//          value.
		// acquire ==> See above.
		// ordered ==> Both acquire and release ordering properties.

	// This version gives direct access to the hardware primitives, and fails
	// if they don't exist.  As a result, it should be OK for inter-process
	// and signal-handler communication, though that's beyond the standard.
	template <class T>
	class native_atomic {
		public:
		static bool basics_supported();
			// Are load/store primitives supported?
		native_atomic(T);
			// No ordering semantics, constructor itself not atomic.
		
		// The following may fail if basics_supported() returns false.
		// A store_release, or an atomic update with a release
		// argument, "synchronizes with" a load_acquire or an atomic
		// update with an acquire argument.  There are no other
		// such relationships.
		template <ordering_constraint c>
			void store(const T&);
			// c가 acquire면 컴파일 타임 에러
		template <ordering_constraint c>
			T load();
			// c가 none도 acquire도 아니면 컴파일 타임 에러
		
		static bool cas_supported();
			// 비교 후 교환(compare_and_swap)을 지원하는가?
			// If so, the various fetch_and_... primitives
			// are also presumed to be supported for numeric
			// types T, since they
			// can be emulated with a CAS loop.
			// Cas is not guaranteed to be
			// wait-free, though it should be if the hardware
			// provides them.
		// There was a suggestion that the above be static, for this
		// version only.  I'm not sure that's right, given that portable
		// code should probably be prepared to adjust dynamically.

		// Compare-and-swap.  Does not fail spuriously.  Not wait-free
		// on ll-sc machines.
		template <ordering_constraint c>
			bool cas(const T& old, const T& new_val);
		static bool cas_is_wait_free();

		// Compare-and-swap.  May fail spuriously.  Wait-free
		// on ll-sc machines.
		template <ordering_constraint c>
			bool weak_cas(const T& old, const T& new_val);
		static bool weak_cas_is_wait_free();

		// I'm inclined to restrict double-width operations to
		// the low level interface, if we provide them at all.
		// They're very difficult to use,
		// due to architectural variation, and would mess up this
		// interface.
		
//		T operator T() { return load<acquire>(); }
		void operator=(const T& x) { return store<release>(x); }

		volatile T m_field;
	};
#if 0
	// The following provides the same interface, but the primitives
	// always have functional implementations, possibly because they are
	// emulated with locks.
	// The implementation should avoid emulation whenever the hardware
	// provides suitable primitives.
	// We expect that the canonical implementation will provide a static
	// hash table of locks, and map each address to a location in the hash
	// table.
	// Since the implementation may be lock-based, this version is NOT useful
	// for either signal-handler or inter-process communication.  (Again,
	// this is beyond the scope of the standard, but non-normative text
	// should make that clear to avoid accidents.)  It is only useful
	// for inter-thread communication, which would like to avoid the overhead of
	// a full lock in most cases, but needs to run everywhere to some
	// extent.  Based on limited experience, we nonetheless believe
	// that this is a common case.

	template <class T>
	class atomic {
		public:
		static bool basics_supported()	{ return true; }
			// 항상 true를 반환.
		atomic(T);
			// No ordering semantics, constructor not atomic.
		template <ordering_constraint c>
			void store(const T&);
			// c가 none도 release도 아니면 컴파일 타임 에러
		template <ordering_constraint c>
			T load();
			// c가 none도 acquire도 아니면 컴파일 타임 에러
		
		static bool cas_supported();
			// 항상 true를 반환
			// native_atomic::cas_supported()가 true를 반환하면 Lock free

		// 비교 후 교환(Compare-and-swap).  Does not fail spuriously.  Not wait-free
		// on ll-sc machines.
		template <ordering_constraint c>
			bool cas(const T& old, const T& new_val);
		static bool cas_is_wait_free();

		// 비교 후 교환(Compare-and-swap).  May fail spuriously.  Wait-free
		// on ll-sc machines.
		template <ordering_constraint c>
			bool weak_cas(const T& old, const T& new_val);
		static bool weak_cas_is_wait_free();

		T operator T() { return load<acquire>(); }
		void operator=(const T& x) { return store<release>(x); }


	// Atomic integral data type with fetch_and_... operations.
	// Meaningful unly if the argument T is an integral type.  
	template <class T=int>
	class native_atomic_int : public native_atomic<T> {
		public:
		native_atomic_int(T);
			// No ordering semantics, not atomic.
		// The fetch_op functions may fail if cas_supported() yields false.
		// These are also not guaranteed to be wait-free, and hence
		// can be trivially emulated with cas.  We provide them
		// directly for convenience, and since they may have slightly
		// faster implementations.
		// They return the original value of the atomic.
		template <ordering_constraint c>
			T fetch_add(T);
		static bool fetch_add_is_wait_free();
			// Is the operation wait-free?
		template <ordering_constraint c>
			T fetch_and(T);
		static bool fetch_and_is_wait_free();
		template <ordering_constraint c>
			T fetch_or(T);
		static bool fetch_or_is_wait_free();
	};

	template <class T=int>
	class atomic_int : public atomic<T> {
		public:
		atomic_int(T);
			// No ordering semantics, not atomic.
		// The fetch_op functions always succeed, but are guaranteed
		// to be lock-free only id native_atomic::cas_supported yields
		// true.
		template <ordering_constraint c>
			T fetch_add(T);
		static bool fetch_add_is_wait_free();
			// Is the operation wait-free?
		template <ordering_constraint c>
			T fetch_and(T);
		static bool fetch_and_is_wait_free();
		template <ordering_constraint c>
			T fetch_or(T);
		static bool fetch_or_is_wait_free();
	};

	// Adds fetch_and_... operations to a pointer type.
	// Meaningful unly if T is a pointer type.
	template <class T>
	class native_atomic_ptr : public native_atomic<T> {
		public:
		native_atomic_ptr(T);
			// No ordering semantics, not atomic.
		// The following may fail if native_atomic<T>::cas_supported()
		// yields false.
		// This atomic pointer addition or
		// subtraction, i.e. a multiple of the object size is added
		// to the address.
		// Also by analogy to basic pointer types, we do not directly
		// provide for tags.
		template <ordering_constraint c> T fetch_and_add(ptr_diff_t);
		static bool fetch_add_is_wait_free();
	};

	// Adds fetch_and_... operations to a pointer type.
	// Meaningful unly if T is a pointer type.
	template <class T>
	class atomic_ptr : public atomic<T> {
		public:
		atomic_ptr(T);
			// No ordering semantics, not atomic.
		// Always succeeds, since it may be emulated with locks.
		template <ordering_constraint c> T fetch_and_add(ptr_diff_t);
		static bool fetch_add_is_wait_free();
	};

	// This is an attempt at providing low-level C style
	// atomics.  This does not follow existing precedent, in that we are
	// very explicit about ordering constraints.

	// All primitives have corresponding feature tests.
	// Each feature test macro is either:
	//   - undefined if no instance of the platform defines the feature, or
	//   - defined to a possibly non-constant (in the C/C++ sense) expression
	//     which evaluates to a nonzero value if the feature is present on the
	//     current machine.
	// For example, ATOMIC_HAVE_INT_CAS would be undefined on an architecture
	// such as PA-RISC, which does not provide a hardware compare-and-swap
	// operation, but it would be defined to a runtime expression, which tests
	// that the processor is at least a 486 when compiling generic (386 or better)
	// X86 code.  On an architecture like Itanium, where all instances provide
	// the operation, it would be defined to a nonzero constant such as 1.
	//
	// Thus most uses of these macros would be of the form
	//      # ifndef ATOMIC_HAVE_...
	//	#   define ATOMIC_HAVE_... 0
	//	# endif
	//
	// 	if (ATOMIC_HAVE_...)
	//	  < code that uses atomic operations >
	//      else
	//	  < lock-based code >
	//
	// #ifndef ATOMIC_HAVE_...
	// can be used to substitute alternate code on platforms that never provide
	// the feature.
	//
	// This arrangement does not allow a preprocessor test for whether the
	// feature is defined on all instances of the processor.  Our guess is that
	// this is not particularly useful.  Typically if any instances provide it,
	// nearly all future instances will, and thus code should include the
	// dynamic tests.
	//
	// We could provide both static and dynamic feature tests directly, but
	// that significantly increases the size of the interface.  Or we could
	// eliminate the static test, but that would make it harder to deal with
	// cases (such as a linked stack) that are likely to use different 
	// data structured depending the availability of primitives.  Thus this
	// compromise.

	// Some feature test macros
	#define ATOMIC_HAVE_CHAR_BASICS <impl. defined>
		// nonzero if ordered & unordered load/store primitives on
		// char and unsigned char are supported.
	#define ATOMIC_HAVE_SHORT_BASICS <impl. defined>
	#define ATOMIC_HAVE_INT_BASICS <impl. defined>
	#define ATOMIC_HAVE_LONG_BASICS <impl. defined>
	#define ATOMIC_HAVE_PTR_BASICS <impl. defined>
		// 1 if ordered & unordered load/store primitives on
		// void * are supported.
	void atomic_memory_fence(void);     // Guarantees explicit memory ordering
						 // for otherwise unordered atomics,
						 // and for other memory references wrt
						 // atomics.  Not useful for ordering
						 // ordinary memory references, since
						 // those may not race and, if they don't
						 // race, always appear to be ordered.
	void atomic_compiler_fence(void);   // Ensures that prior memory operations
						 // appear in the instruction stream
						 // before subsequent ones, i.e. the
						 // compiler is not allowed to reorder
						 // around this.  This really has only
						 // implementation-defined semantics,
						 // but it seems to be useful in
						 // ensuring ordering with respect to
						 // signal handlers and the like.
					     
	// I will assume that the following are overloaded for T in (void *)
	// and unsigned {char, short, int, long}.
	// A signed version can be derived from the unsigned.
	// (In a strictly conforming program, I think this requires adding an
	// explicit bias.  In practice, it's a non-issue.)
	// They may not be applied to user-defined types.
	// The semantics of primitives whose corresponding feature test macro is
	// not defined are left undefined.  Implementations that fail conspicuously
	// are preferred over implementations that occasionally produce unexpected
	// outcomes, w.g. by relaxing the atomicity constraint.
	void atomic_store(T*, T);  // No ordering guarantees.
	void atomic_store_release(T*, T);

	template<typename T>
	T atomic_load( atomic<T>* );	// No ordering guarantees.

	template<typename T>
	T atomic_load_acquire(T*);

	#define ATOMIC_HAVE_T_CAS  <impl. defined>
		// Abbreviates 5 different feature tests for different
		// replacements of T.

	#define ATOMIC_HAVE_WAIT_FREE_T_CAS  <impl. defined>
		// Abbreviates 5 different feature tests for different
		// replacements of T.  Indicates whether the below
		// operation is wait-free.  Undefined if it is never wait-free.

	T atomic_cas[_order](T* addr, T old_val, T new_val);
		// Order can be any of raw, acquire, release, or ordered.
		// "Raw" implies the operation is unordered.
		// Most architectures provide a way to return the old
		// value.  On those that do not, it can be emulated with
		// an additional load, at the expense of wait-freedom
		// or spurious failure.

	#define ATOMIC_HAVE_WEAK_T_CAS  <impl. defined>
	T atomic_weak_cas[_order](T* addr, T old_val, T new_val);
		// Similar to the above, but may fail spuriously, and
		// must be wait-free, if provided.

	// It is unclear how various flavors of double-wide or two operand
	// CAS should be handled.  We omit them here.  That may in fact
	// be a reasonable alternative.

	#define ATOMIC_HAVE_T_FETCH_ADD <impl. defined>
		// Abbreviates 5 different feature tests for different
		// replacements of T.

	T atomic_fetch_add[_order](T* addr, T incr);
		// Order can be any of acquire, release, or ordered.
		// If it is omitted, the operation is unordered.

	#define ATOMIC_HAVE_T_FETCH_OR <impl. defined>

	T atomic_fetch_or[_order](T* addr, T mask);

	#define ATOMIC_HAVE_T_FETCH_AND <impl. defined>

	T atomic_fetch_and[_order](T* addr, T mask);

	// A simple test-and-set primitive.  We probably don't need a
	// feature test macro, since this pretty much has to be supported.
	typedef enum {atomic_ts_clear, atomic_ts_set} atomic_ts_val;

	typedef <implementation defined> atomic_ts_loc;
		// Needs strange alignments, etc on some architectures.

	atomic_ts_val atomic_ts(atomic_ts_loc *addr);

	void atomic_ts_clear(atomic_ts_loc *addr);
	void atomic_ts_clear_release(atomic_ts_loc *addr);

	#define ATOMIC_TS_LOC_INITIALIZER <implementation defined>
		// Initialization expression for cleared atomic_ts_loc.
#endif

	// OGRE3D에서 가져온 atomic_calar 템플릿(임시)
	template<typename T>
	class atomic_scalar
	{
	public:
		atomic_scalar();
		atomic_scalar( const T& v );
		atomic_scalar( const atomic_scalar<T>& v );
		operator T();

		void	store( const T& v );
		T		load		() const;
		bool	cas			( const T& old, const T& nu );
		T		operator++	();
		T		operator--	();
		T		operator++	( int );
		T		operator--	( int );

		volatile	T		field;
		static		size_t	size;
	};
}

#endif	/* _MH_STL_ATOMIC_HPP_ */