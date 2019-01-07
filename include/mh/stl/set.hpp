#ifndef	_MH_STL_SET_HPP_
#define	_MH_STL_SET_HPP_

#include "iterator.hpp"
#include "utility.hpp"
#include "allocator.hpp"

namespace Mh
{
	template<typename Key, typename Compare = less<Key>, typename Allocator = Allocator<Key> >
	class set
	{
	public:
		typedef	Key			key_type;
		typedef	Key			value_type;
		typedef	Compare		key_compare;
		typedef	Compare		value_compare;
		typedef	Allocator	allocator_type;
		typedef	typename Allocator::pointer			pointer;
		typedef	typename Allocator::const_pointer	const_pointer;
		typedef	typename Allocator::reference		reference;
		typedef	typename Allocator::const_reference	const_reference;
		typedef	typename Allocator::size_type		size_type;
		typedef	typename Allocator::difference_type	difference_type;

		class iterator
		{
		};
		
		class const_iterator
		{
		};

		typedef	reverse_iterator<iterator>			reverse_iterator;
		typedef	const_reverse_iterator<iterator>	const_reverse_iterator;

	public:
		/*!
		 *	생성자
		 */
		explicit set( const Compare& comp = Compare(), const Allocator& = Allocator() );
		template<typename InputIterator> set( InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator() );
		set( const set<Key, Compare, Allocator>& x );

		/*!
		 *	소멸자
		 */
		~set();

		/*!
		 *	대입 연산자
		 */
		set<Key, Compare, Allocator>& operator = ( const set<Key, Compare, Allocator>& x );

		iterator			begin();
		const_iterator		begin() const;
		iterator			end();
		const_iterator		end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		/*!
		 *	empty()
		 *
		 *	\brief	컨테이너에 요소가 들어있는지 확인
		 */
		bool empty() const;

		/*!
		 *	size()
		 *
		 *	\brief	컨테이너에 들어있는 요소의 갯수를 돌려줌
		 */
		size_type	size() const;

		/*!
		 *	max_size()
		 *
		 *	\brief	컨테이너에 들어갈 수 있는 요소의 최대 개수를 리
		 */
		size_type max_size() const;

		/*!
		 *	insert()
		 *
		 *	\brief	요소를 추가
		 */
		pair<iterator, bool>	insert( const value_type& x );
		iterator				insert( iterator position, const value_type& x );
		template<InputIterator> void insert( InputIterator first, InputIterator last );

		void		erase( iterator position );
		size_type	erase( const key_type& x );
		void		erase( iterator first, iterator last );
	};

}		// namespace Mh

#endif	/* _MH_STL_SET_HPP_ */