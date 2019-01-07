#ifndef	_MH_STL_LIST_HPP_
#define	_MH_STL_LIST_HPP_

#include "utility.hpp"
#include "allocator.hpp"

/*
 *	엄밀히 말해 STL은 아니지만... 일단 연습삼아 만들어보고 나중에 조금씩 바꿔나가자
 */

namespace Mh
{
	// 차후에 반복자와 할당자 만들기
	template<typename T, class Allocator = Allocator<T> >
	class list
	{
	public:
		typedef Allocator							allocator_type;
		typedef	typename Allocator::value_type		value_type;
		typedef typename Allocator::pointer			pointer;
		typedef	typename Allocator::const_pointer	const_pointer;
		typedef	typename Allocator::reference		reference;		
		typedef	typename Allocator::const_reference	const_reference;
		typedef	typename Allocator::size_type		size_type;
		typedef	typename Allocator::difference_type	difference_type;

#if 1
		typedef	T*				iterator;
		typedef	const T*		const_iterator;
#else
		template<typename T>
		struct iterator
		{
		public:
			typedef	T		value_type;

			iterator();
			iterator( const iterator& );

			const iterator& operator = ( const iterator& );

			iterator& operator ++ ();
			iterator& operator -- ();
			iterator operator ++ ( int );
			iterator operator -- ( int );
			
			bool operator == ( const iterator& );
			bool operator != ( const iterator& );

		private:
			ListNode*		m_node;
		};

		class const_iterator
		{
		public:
			const_iterator();
		};
#endif

	private:
		struct ListNode
		{
			T			value;
			ListNode*	prev;
			ListNode*	next;

			ListNode( const T& _value, ListNode* _prev, ListNode* _next )
				:	value(_value), prev(_prev), next(_next)
			{}
		};
		typedef	typename Allocator::rebind<ListNode>::other	real_allocator_type;

	public:

		/*!
		 *	List()
		 *
		 *	\brief	생성자
		 */
		explicit list( const Allocator& allocator = Allocator() );
		explicit list( size_type n, const T& value = T(), const Allocator& allocator = Allocator() );
		template<typename InputIterator> list( InputIterator first, InputIterator last, const Allocator& allocator = Allocator() );
		list( const list<T, Allocator>& x );

		/*!
		 *	~List()
		 *
		 *	\brief	소멸자
		 */
		~list();
		
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
	//	reverse_iterator		rbegin();
	//	const_reverse_iterator	rbegin() const;
	//	reverse_iterator		rend();
	//	const_reverse_iterator	rend() const;
		bool					empty() const;
		size_type				size() const;
		size_type				max_size() const;

		/*!
		 *	resize()
		 *
		 *	\brief	컨테이너 사이즈 변경
		 *	\param	sz		변경할 사이즈 크기
		 *	\param	c		컨테이너가 커졌을때 채울 방법
		 *	\return	없음
		 */
		void resize( size_type sz, T c = T() );

		/*!
		 *	front()
		 *
		 *	\brief	컨테이너의 첫번째 요소의 참조를 반환
		 *	\param	없음
		 *	\return	첫번째 요소의 참조
		 */
		reference front();
		const_reference front() const;

		/*!
		 *	back()
		 *
		 *	\brief	컨테이너의 마지막 요소의 참조를 반환
		 *	\param	없음
		 *	\return	마지막 요소의 참조
		 */
		reference back();
		const_reference back() const;

		/*!
		 *	assign()
		 *
		 *	\brief	컨테이너에 새로운 내용을 추가
		 *	\param	first,last	초기화할 연속적인 입력반복자. [first:last)
		 *	\param	n	추가할 횟수
		 *	\param	u	추가할 객체
		 *	\return	없음
		 */
		template<typename InputIterator> void assign( InputIterator first, InputIterator last );
		void assign( size_type n, const T& u );

		/*!
		 *	push_front()
		 *
		 *	\brief	컨테이너의 시작 부분에 새 요소 추가
		 *	\param	x	추가할 요소
		 *	\return	없음
		 */
		void push_front( const T& x );

		/*!
		 *	push_back()
		 *
		 *	\brief	컨테이너의 마지막에 새 요소 추가
		 *	\param	x	추가할 요소
		 *	\return	없음
		 */
		void push_back( const T& x );

		/*!
		 *	pop_front()
		 *
		 *	\brief	첫번째 요소를 제거
		 *	\param	없음
		 *	\return	없음
		 */
		void pop_front();

		/*!
		 *	pop_back()
		 *
		 *	\brief	마지막 요소를 제거
		 *	\param	없음
		 *	\return	없음
		 */
		void pop_back();

		/*!
		 *	insert()
		 *
		 *	\brief	요소를 추가
		 *	\param	position	추가할 위치
		 *	\param	x			추가할 요소
		 *	\param	n			추가할 횟수
		 *	\param	first,last	추가할 요소의 범위를 가리키는 반복자
		 *	\return	iterator	새롭게 추가된 요소를 가리키는 반복자
		 */
		iterator insert( iterator position, const T& x );
		void insert( iterator position, size_type n, const T& x );
		template<typename InputIterator> void insert( iterator first, iterator last );

		/*!
		 *	erase()
		 *
		 *	\brief	컨테이너에서 특정 요소를 제거
		 *	\param	position	제거할 요소의 위치
		 *	\param	first,last	제거할 요소의 범위를 가리키는 반복자
		 */
		iterator erase( iterator position );
		iterator erase( iterator first, iterator last );

		/*!
		 *	swap()
		 *
		 *	\brief	컨테이너의 내용을 맞바꿈
		 *	\param	list	내용을 맞바꿀 같은 타입의 리스트
		 *	\return	없음
		 */
		void swap( list<T, Allocator>& r );

		/*!
		 *	clear()
		 *
		 *	\brief	컨테이너의 모든 요소를 제거
		 *	\param	없음
		 *	\return	없음
		 */
		void clear();

		/*!
		 *	splice()
		 *
		 *	\brief	다른 리스트의 요소를 가져옴
		 *	\param	position	추가할 위치
		 *	\param	x			가져올 리스트
		 *	\param	i			가져올 요소의 위치를 가리키는 반복자
		 *	\param	first,last	가져올 요소의 범위를 가리키는 반복자
		 */
		void splice( iterator position, list<T, Allocator>& x );
		void splice( iterator position, list<T, Allocator>& x, iterator i );
		void splice( iterator position, list<T, Allocator>& x, iterator first, iterator last );

		/*!
		 *	remove()
		 *
		 *	\brief	특정 값을 가진 요소를 제거
		 *	\param	value	지울 요소의 값
		 *	\return	없음
		 */
		void remove( const T& value );

		/*!
		 *	remove_if()
		 *
		 *	\brief	조건 수행을 통해 요소 제거
		 *	\param	pred	조건을 판단하는 단항 함수자
		 *	\return	없음
		 */
		template<typename Predicate> void remove_if( Predicate pred );

		/*!
		 *	unique()
		 *
		 *	\brief	중복된 값을 삭제
		 *	\param	binary_pred
		 *	\return	없음
		 */
		void unique();
		template<typename BinaryPredicate> void unique( BinaryPredicate binary_pred );

		/*!
		 *	merge()
		 *
		 *	\brief	정렬된 리스트를 병합
		 *	\param	x		병합할 리스트
		 *	\param	comp	비교함수자
		 *	\return	없음
		 */
		void merge( list<T, Allocator>& x );
		template<typename Compare> void merge( list<T, Allocator>& x, Compare comp );

		/*!
		 *	sort()
		 *
		 *	\brief	요소를 정렬
		 *	\param	comp	술어구문 함수자
		 */
		void sort();
		template<class Compare> void sort( Compare comp );

		/*!
		 *	reverse()
		 *
		 *	\brief	요소의 순서를 반전
		 *	\param	없음
		 *	\return	없음
		 */
		void reverse();

		/*!
		 *	get_allocator()
		 *
		 *	\brief	컨테이너를 생성하는 할당자를 반환
		 *	\param	없음
		 *	\return	리스트의 할당자
		 */
		allocator_type get_allocator() const;


		/*!
		 *	operator =
		 *
		 *	\brief	대입연산자. assign과 동일
		 *	\param	list
		 */
		const list& operator = ( const list<T, Allocator>& list );

	private:
		size_type		m_size;
		size_type		m_capacity;
		ListNode*		m_head;
	};

	/*!
	 *	리스트용 비교 연산자
	 */
	template <class T, class Allocator>	bool operator == ( const list<T, Allocator>& l, const list<T, Allocator>& r );
	template <class T, class Allocator>	bool operator != ( const list<T, Allocator>& l, const list<T, Allocator>& r );
	template <class T, class Allocator>	bool operator <= ( const list<T, Allocator>& l, const list<T, Allocator>& r );
	template <class T, class Allocator>	bool operator >= ( const list<T, Allocator>& l, const list<T, Allocator>& r );
	template <class T, class Allocator>	bool operator < ( const list<T, Allocator>& l, const list<T, Allocator>& r );
	template <class T, class Allocator>	bool operator > ( const list<T, Allocator>& l, const list<T, Allocator>& r );

	template<typename T, typename Allocator> void swap( list<T, Allocator>& l, list<T, Allocator>& r );

#include "list.inl"
}

#endif	/* _MH_LIST_HPP_ */