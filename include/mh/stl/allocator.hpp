#ifndef	_MH_STL_ALLOCATOR_HPP_
#define	_MH_STL_ALLOCATOR_HPP_

#include <new>
#include <memory>
#include "prerequisite.h"

namespace Mh
{
	/*
	 *	테스트용 커스텀 할당자(작성중)
	 */
	template<typename T>
	class allocator
	{
	public:
		typedef	size_t		size_type;
		typedef	ptrdiff_t	difference_type;
		typedef	T			value_type;
		typedef	T*			pointer;
		typedef	const T*	const_pointer;
		typedef	T&			reference;
		typedef	const T&	const_reference;

		template<typename U> struct rebind { typedef allocator<U> other; };

	public:
		allocator() throw();
		allocator( const allocator& ) throw();
		template<typename U> allocator( const allocator<U>& ) throw();
		~allocator() throw();

		static	pointer			address( reference r );
		static	const_pointer	address( const_reference c );
		static	size_type		max_size();

		static	pointer			allocate( size_type n, const void* hint = 0 );
		static	void			deallocate( pointer p, size_type n );
		static	void			construct( pointer p, const_reference val );
		static	void			destroy( pointer p );
	};

	template <class T1, class T2> bool operator==(const allocator<T1>&, const allocator<T2>&) throw();
	template <class T1, class T2> bool operator!=(const allocator<T1>&, const allocator<T2>&) throw();

#include "allocator.inl"

}		// namespace Mh

#endif	/* _MH_ALLOCATOR_HPP_ */