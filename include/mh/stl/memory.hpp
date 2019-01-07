#ifndef	_MH_STL_MEMORY_HPP_
#define	_MH_STL_MEMORY_HPP_

//#include "type_traits.hpp"
//#include "iterator.hpp"
//#include "algorithm.hpp"

#include <memory>

/*
 *	스마트 포인터 구현 연습
 */
namespace Mh
{
	/*!
	 *	스마트 포인터 기본 타입. 잘하는 짓인지 나도 모르겠다.
	 */
	template<typename T>
	class _base_ptr
	{
	public:
		typedef	T	element_type;

	public:

	protected:
		_base_ptr()			{}
		~_base_ptr()		{}

	};


	/*!
	 *
	 */
	template<typename T>
	struct auto_ptr_ref
	{
		explicit auto_ptr_ref( T* r ) : ref( r ) {}

		T* ref;
	};

	/*!
	 *	auto_ptr
	 *
	 *	\note	deprecated. 연습용으로만 만들고 쓰지마라...
	 */
	template<typename T>
	class auto_ptr
	{
	public:
		typedef	T	element_type;

	public:
		// 생성자
		explicit auto_ptr( T* p = 0 ) throw();
		auto_ptr( auto_ptr& r ) throw();
		template<typename U> auto_ptr( auto_ptr<U>& r ) throw();
		auto_ptr( auto_ptr_ref<T> r ) throw();
		~auto_ptr() throw();

		template<typename U> operator auto_ptr_ref<U>() throw();
		template<typename U> operator auto_ptr<U>() throw();

		T*		get() const throw();
		T*		release() throw();
		void	reset( T* p = 0 ) throw();

		T&			operator *	() const throw();
		T*			operator ->	() const throw();
		auto_ptr&	operator =	( auto_ptr& r ) throw();
		template<typename U> auto_ptr&	operator =	( auto_ptr<U>& r ) throw();
		auto_ptr&	operator =	( auto_ptr_ref<T> r ) throw();

	private:
		T*	m_ptr;
	};

	// void 타입에 대한 특수화
	template<>
	class auto_ptr<void>
	{
	public:
		typedef	void	element_type;
	};

	template<typename T> class weak_ptr;

	/*!
	 *	shared_ptr
	 *
	 *	\note	연습용. 객기로라도 쓰지마라...
	 */
	template<typename T>
	class shared_ptr : public _base_ptr<T>
	{
	public:

	public:
		shared_ptr();
		template<typename U> explicit shared_ptr( U* ptr );
		template<typename U, typename Deleteter> shared_ptr( U* ptr, Deleter d );
		shared_ptr( const shared_ptr& p );
		template<typename U> shared_ptr( const shared_ptr<U>& p );
		template<typename U> shared_ptr( const weak_ptr<U>& p );
		template<typename U> shared_ptr( const auto_ptr<U>& p );
#if	(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_CONSTEXPR_)
		constexpr shared_ptr();
#endif
#if	(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_NULLPTR_)
	//	template<typename Deleter> shared_ptr( nullptr, Deleter d );
#endif

	//	operator boolean-type() const;

		shared_ptr&	operator =	( const shared_ptr& r );
		template<typename U> shared_ptr& operator =	( const shared_ptr<U>& p );
		template<typename U> shared_ptr& operator =	( const auto_ptr<U>& p );

		void	swap( shared_ptr& p );
		void	reset();
		template<typename U> void reset( U* p );
		template<typename U, class Deleter> void reset( U* p, Deleter d );

		T*		get() const;
		T&		operator *	() const;
		T*		operator ->	() const;
		long	use_count() const;
		bool	unique() const;

	private:
		// 레퍼런스 카운트 객체 포인터
		//RefCnt*	m_ref;
		T*	m_ptr;
	};

	template<typename T1, typename T2>	bool operator ==	( const shared_ptr<T1>& l, const shared_ptr<T2>& r );
	template<typename T1, typename T2>	bool operator !=	( const shared_ptr<T1>& l, const shared_ptr<T2>& r );
	template<typename T1, typename T2>	bool operator <		( const shared_ptr<T1>& l, const shared_ptr<T2>& r );
	//template<typename Elem, class Trait, class T>	baisc_ostream<Elem, Tr>& operator <<
	template<typename T> void swap( shared_ptr<T>& l, shared_ptr<T>& r );

	/*!
	 *	weak_ptr
	 */
	template<typename T>
	class weak_ptr : public _base_ptr<T>
	{
	public:
		weak_ptr();
		weak_ptr( const weak_ptr& p );
		template<typename U> weak_ptr( const weak_ptr<U>& p );
		template<typename U> weak_ptr( const shared_ptr<U>& p );
		~weak_ptr();

		weak_ptr&	operator =	( const weak_ptr& p );
		template<typename U> weak_ptr&	operator =	( const weak_ptr<U>& p );
		template<typename U> weak_ptr&	operator =	( const shared_ptr<U>& p );

		void	swap( weak_ptr& p );
		void	reset();

		long	use_count() const;
		bool	expired() const;
		shared_ptr<T>	lock() const;
	};

	template<typename T1, typename T2>	bool operator <	( const weak_ptr<T1>& l, const weak_ptr<T2>& r );
	template<typename T> void swap( weak_ptr<T>& l, weak_ptr<T>& r );
	
	// 편의용 클래스 및 템플릿
	template<typename T> class enable_shared_from_this;
	class bad_weak_ptr;

	// 함수
	template<typename T, typename U> shared_ptr<T> const_pointer_cast( const shared_ptr<U>& p );
	template<typename T, typename U> shared_ptr<T> static_pointer_cast( const shared_ptr<U>& p );
	template<typename T, typename U> shared_ptr<T> dynamic_pointer_cast( const shared_ptr<U>& p );


#include "memory.inl"
}

#endif	/* _MH_STL_MEMORY_HPP_ */