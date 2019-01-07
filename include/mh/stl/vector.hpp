#ifndef	_MH_STL_VECTOR_HPP_
#define	_MH_STL_VECTOR_HPP_

#include <mh/allocator.hpp>
#include "iterator.hpp"
#include "algorithm.hpp"

/*
 *	연습삼아 만들어보는 STL
 */

namespace Mh
{
	template<typename T, typename Allocator = allocator<T> >
	class vector
	{
	public:
		typedef	T			value_type;
		typedef	Allocator	allocator_type;
		typedef	typename Allocator::size_type		size_type;
		typedef	typename Allocator::difference_type	difference_type;
		typedef	typename Allocator::pointer			pointer;
		typedef	typename Allocator::const_pointer	const_pointer;
		typedef	typename Allocator::reference		reference;
		typedef	typename Allocator::const_reference	const_reference;

		class iterator
		{
		public:
			iterator();
		};

		class const_iterator
		{
		public:
			const_iterator();
		};

		typedef Mh::reverse_iterator<iterator>			reverse_iterator;
		typedef Mh::reverse_iterator<const_iterator>	const_reverse_iterator;

	public:
		/*
		 *	생성자
		 */
		explicit vector( const Allocator& a = Allocator() );
		explicit vector( size_type n, const T& value = T(), const Allocator& = Allocator() );
		template<typename InputIterator>
			vector( InputIterator first, InputIterator last, const Allocator& = Allocator() );
		vector( const vector<T, Allocator>& x );
		
		/*
		 *	소멸자
		 */
		~vector();

		reference		at( size_type n );
		const_reference	at( size_type n ) const;
		
		reference		back() const;
		const_reference	back();
		
		reference		front() const;
		const_reference	front();
		
		iterator		begin();
		const_iterator	begin() const;

		iterator		end();
		const_iterator	end() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		template<typename InputIterator>
			void	assign( InputIterator first, InputIterator last );
		void		assign( size_type n, const T& u );

		iterator	erase( iterator position );
		iterator	erase( iterator first, iterator last );
		
		iterator	insert( iterator position, const T& x );
		void		insert( iterator position, size_type n, const T& x );
		template<typename InputIterator>
			void	insert( iterator position, InputIterator fist, InputIterator last );

		void		pop_back();
		void		push_back( const T& x );

		void		reserve( size_type n );
		void		resize( size_type sz, T c = T() );

		void		swap( vector<T, Allocator>& vec );

		void		clear();
		bool		empty() const;

		size_type	size() const;
		size_type	max_size() const;
		size_type	capacity() const;

		allocator_type	get_allocator() const;

		vector<T, Allocator>&	operator =	( const vector<T, Allocator>& x );
		reference				operator []	( size_type n );
		const_reference			operator []	( size_type n ) const;

	private:
		value_type*		m_buffer;
		size_type		m_size;
		size_type		m_capacity;
		allocator_type	m_allocator;
	};

	template<typename T, class Allocator> bool operator ==	( const vector<T, Allocator>& x, const vector<T, Allocator>& y );
	template<typename T, class Allocator> bool operator !=	( const vector<T, Allocator>& x, const vector<T, Allocator>& y );
	template<typename T, class Allocator> bool operator <=	( const vector<T, Allocator>& x, const vector<T, Allocator>& y );
	template<typename T, class Allocator> bool operator >=	( const vector<T, Allocator>& x, const vector<T, Allocator>& y );
	template<typename T, class Allocator> bool operator <	( const vector<T, Allocator>& x, const vector<T, Allocator>& y );
	template<typename T, class Allocator> bool operator >	( const vector<T, Allocator>& x, const vector<T, Allocator>& y );

	template<typename T, class Allocator> void swap( vector<T, Allocator>& l, vector<T, Allocator>& r );

	// bool 타입에 대한 특수화(구현 안됨)
	template<typename Allocator>
	class vector<bool, Allocator>
	{
	public:
		class reference
		{
			friend class vector<bool>;
			reference();

		public:
			~reference();
			operator bool() const;
			reference& operator = ( bool x );
			reference& operator = ( const reference& x );
			void flip();
		};

	public:
	};

#include "vector.inl"

}

#endif	/* _MH_STL_VECTOR_HPP_ */