#ifndef	_MH_STL_ITERATOR_HPP_
#define	_MH_STL_ITERATOR_HPP_

#include <cstddef>

namespace Mh
{
	// 반복자 태그
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// 반복자 특성 템플릿
	template<typename Iterator>
	struct iterator_traits
	{
		typedef	typename Iterator::iterator_category	iterator_category;
		typedef	typename Iterator::difference_type		difference_type;
		typedef	typename Iterator::value_type			value_type;
		typedef	typename Iterator::pointer				pointer;
		typedef	typename Iterator::reference			reference;
	};

	// 특성 템플릿의 포인터 타입에 대한 특수화
	template<typename T>
	struct iterator_traits<T*>
	{
		typedef T			value_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef ptrdiff_t	difference_type;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef T			value_type;
		typedef const T*	pointer;
		typedef const T&	reference;
		typedef ptrdiff_t	difference_type;
		typedef random_access_iterator_tag	iterator_category;
	};


	template<typename Category, class T,
		class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_catergory;
	};


	template<typename Iterator>
	class reverse_iterator
	{
	public:
		typedef	Iterator	iterator;
		typedef	typename iterator_traits<Iterator>::value_type			value_type;
		typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename iterator_traits<Iterator>::pointer				pointer;
		typedef	typename iterator_traits<Iterator>::reference			reference;
		typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;

	public:
		/*!
		 *	생성자
		 */
		reverse_iterator();
		explicit reverse_iterator( Iterator it );
		template<typename U> reverse_iterator( const reverse_iterator<U>& u );

		Iterator base() const;
		/*!
		 *	역참조 연산자
		 */
		pointer		operator ->	() const;
		reference	operator *	() const;
		reference	operator []	( difference_type n ) const;
		
		reverse_iterator&	operator ++	();
		reverse_iterator	operator ++	( int );
		reverse_iterator&	operator --	();
		reverse_iterator	operator --	( int );
		reverse_iterator&	operator +=	( difference_type n );
		reverse_iterator&	operator -=	( difference_type n );
		reverse_iterator	operator +	( difference_type n ) const;
		reverse_iterator	operator -	( difference_type n ) const;
	};

#include "iterator.inl"

}

#endif	/* _MH_STL_ITERATOR_HPP_ */