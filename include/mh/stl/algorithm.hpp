#ifndef	_MH_STL_ALGORITHM_HPP_
#define	_MH_STL_ALGORITHM_HPP_

#include <mh/utility.hpp>

/*
 *	알고리즘
 */
namespace Mh
{
#ifndef min
	/*
	 *	min
	 *
	 *	\brief	두 인수 중 작은 것을 반환
	 *	\note	일부 헤더(windef.h 등)에서 매크로 함수로 선언되어 있을 경우에는 사용하지 않음
	 */
	template<typename T>
	const T& min(const T& a, const T& b);
	
	template<typename T, typename Compare>
	const T& min(const T& a, const T& b, Compare comp);
#endif // min

	/*
	*	min_element
	*
	*	\brief	지정된 범위에서 가장 작은 것의 반복자를 반환
	*/
	template<typename ForwardIterator>
	ForwardIterator min_element(ForwardIterator first, ForwardIterator last);
	
	template<typename ForwardIterator, typename Compare>
	ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp);

#ifndef max
	/*
	 *	max
	 *
	 *	\brief	두 인수 중 큰 것을 반환
	 */
	template<typename T>
	const T& max(const T& a, const T& b);

	template<typename T, typename Compare>
	const T& max(const T& a, const T& b, Compare comp);
#endif	// max

	/*
	 *	max_element
	 *
	 *	\brief	지정된 범위에서 가장 큰 것의 반복자를 반환
	 */
	template<typename ForwardIterator>
	ForwardIterator max_element(ForwardIterator first, ForwardIterator last);

	template<typename ForwardIterator, typename Compare>
	ForwardIterator max_element(ForwardIterator first, ForwardIterator last, Compare comp);

	/*!
	 *	minmax()
	 *
	 *	\breif	두 요소의 크기를 비교한후 pair로 반환
	 *	\note	C++11에서 추가됨
	 *	\todo	initializer_list를 사용한 것이 2개 더 있는데 나중에...
	 */
	template<typename T>
	pair<const T&, const T&> minmax(const T& a, const T& b);

	template<typename T, typename Compare>
	pair<const T&, const T&> minmax(const T& a, const T& b, Compare comp);

	/*
	 *	minmax_element()
	 *
	 *	\brief	지정된 범위에서 가장 작은 것과 큰 것의 반복자를 pair로 반환
	 *	\note	C++11에서 추가됨
	 */
	template<typename ForwardIterator, typename Compare>
	pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last, Compare comp)
	{
		pair<ForwardIterator, ForwardIterator> result(first, last);

		if (first == last)
			return result;
		if (++first == last)
			return result;

		if (comp(*first, *result.first))
			result.first = first;
		else
			result.second = first;

		while (++first != last)
		{
			ForwardIterator iter = first;
			if (++first != last)
			{

			}
			else
			{
				
			}
		}

		return result;
	}

	/*!
	*	clamp()
	*
	*	\brief	두 사이의 값으로 묶음.
	*	\note	C++17에서 추가됨
	*/
	template<typename T>
	const T& clamp(const T& val, const T& lo, const T& hi);

	template<typename T, typename Compare>
	const T& clamp(const T& val, const T& lo, const T& hi, Compare comp);

	/*!
	 *	swap()
	 *
	 *	\brief	두 객체의 값을 바꿈
	 *	\note	C++11에서 람다를 이용하는 추가함수가 있지만 나중에.
	 */
	template<typename T>
	void swap(T& a, T& b);

	// 이하 특수화. 특수화된 게 좀 많음. 이건 각 헤더에 넣아야함;
//	template<typename T, size_t N>
//	void swap( array<T,N>& lhs, array<T,N>& rhs );

	/*!
	 *	iter_swap()
	 *
	 *	\brief	반복자가 가리키는 값을 바꿈
	 */
	template<typename ForwardIterator1, typename ForwardIterator2>
	void iter_swap(ForwardIterator1 a, ForwardIterator2 b);

	/*!
	 *	swap_ranges()
	 *
	 *	\brief	범위 지정 스왑
	 */
	template<typename ForwardIterator1, typename ForwardIterator2>
	ForwardIterator1 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

	/*!
	 *	reverse()
	 *
	 *	\brief	범위의 값을 역순으로 함
	 */
	template<typename BidirectionalIterator>
	void reverse(BidirectionalIterator first, BidirectionalIterator last);

	/*!
	 *	reverse_copy()
	 *
	 *	\brief	범위의 값을 뒤집어서 지정한 곳에 복사
	 */
	template<typename BidirectionalIterator, typename OutputIterator>
	OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator dest);

	/*!
	 *	rotate()
	 *
	 *	\brief	특정 범위를 두 부분으로 나눠서 값을 바꿈
	 *	\note	C++11에서 반환값이 void에서 마지막 값으로 바뀜
	 */
	template<typename ForwardIterator>
	ForwardIterator rotate(ForwardIterator first, ForwardIterator n_first, ForwardIterator last);

	/*!
	 *	rotate_copy()
	 */
	template<typename ForwardIterator, typename OutputIterator>
	OutputIterator rotate_copy(ForwardIterator first, ForwardIterator n_first, ForwardIterator last, OutputIterator dest)
	{
		dest = copy(n_first, last, dest);
		return copy(first, n_first, dest);
	}

	/*!
	 *	unique()
	 */
	template<typename ForwardIterator>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last)
	{
		ForwardIterator result = first;
		while (++first != last)
		{
			if (!(*result == *first))
				*(++result) = *first;
		}
		return ++result;
	}

	template<typename ForwardIterator, typename BinaryPredicate>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate pred)
	{
		ForwardIterator result = first;
		while (++first != last)
		{
			if (!pred(*result, *first))
				*(++result) = *first;
		}
		return ++result;
	}

	/*!
	 *	unique_copy()
	 */
	template<typename ForwardIterator, typename OutputIterator>
	OutputIterator unique_copy(ForwardIterator first, ForwardIterator last, OutputIterator dest)
	{
		*dest = *first;
		while (++first != last)
		{
			if (!(*dest == *first))
				*(++dest) = *first;
		}
		return ++dest;
	}

	template<typename ForwardIterator, typename OutputIterator, typename BinaryPredicate>
	OutputIterator unique_copy(ForwardIterator first, ForwardIterator last, OutputIterator dest, BinaryPredicate pred)
	{
		*dest = *first;
		while (++first != last)
		{
			if (!pred(*dest, *first))
				*(++dest) = *first;
		}
		return ++dest;
	}

	/*!
	 *	for_each()
	 */
	template<typename InputIterator, typename Function>
	Function for_each(InputIterator first, InputIterator last, Function f)
	{
		for (; first != last; ++first) f(*first);
		return f;
	}


	/*!
	 *	find()
	 *
	 *	\brief	범위 내에서 특정 값을 가진 첫번째 요소를 검색
	 */
	template<typename InputIterator, typename T>
	InputIterator find(InputIterator first, InputIterator last, const T& value);

	/*!
	 *	find_if()
	 *
	 *	\brief	범위 내에서 지정한 조건을 만족하는 첫번째 요소를 검색
	 */
	template<typename InputIterator, typename Predicate>
	InputIterator find_if(InputIterator first, InputIterator last, Predicate pred);

	/*!
	 *	find_if_not()
	 *
	 *	\brief	범위 내에서 지정한 조건을 만족하지 않는 첫번재 요소를 검색
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename UnaryPredicate>
	InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred);

	/*!
	 *	find_end()
	 *
	 *	\brief	범위 내에서 조건을 만족하는 마지막 요소를 검색
	 */
	template<typename ForwardIterator1, typename ForwardIterator2>
	ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

	template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
	ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);

	/*!
	 *	find_first_of()
	 */
	template<typename ForwardIterator1, typename ForwardIterator2>
	ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

	template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
	ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);

	/*
	 *	adjacent_find
	 */
	template<typename ForwardIterator>
	ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
	{
		if (first != last)
		{
			ForwardIterator next = first;
			++next;
			while (next != last)
				if (*first++ == *next++)
					return next
		}
		return last;
	}

	template<typename ForwardIterator, typename BinaryPredicate>
	ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred)
	{
		if (first != last)
		{
			ForwardIterator next = first;
			++next;
			while (next != last)
				if (pred(*first++, *next++))
					return next
		}
		return last;
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& value)
	{
		ForwardIterator result = first;
		for (; first != last; ++first)
			if (!(*first == value)) *result++ = *first;
		return result;
	}

	/*
	 *	search()
	 */
	template<typename ForwardIterator1, typename ForwardIterator2>
	ForwardIterator1 search(ForwardIterator1 first, ForwardIterator1 last, ForwardIterator2 s_first, ForwardIterator2 s_last)
	{
		ForwardIterator1 t_last = first;
		size_t cmp_len = distance(first, last) - distance(s_first, s_last) + 1;
		advance(t_last, cmp_len);

		for (; first != t_last; ++first)
		{
			ForwardIterator1 iter = first;
			ForwardIterator2 s_iter = s_first;
			while (*iter == *s_iter)
			{
				++iter;
				++s_iter;

				if (iter == s_iter)
					return first;
			}
		}
		return last;
	}

	template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
	ForwardIterator1 search(ForwardIterator1 first, ForwardIterator1 last, ForwardIterator2 s_first, ForwardIterator2 s_last, BinaryPredicate pred)
	{
		ForwardIterator1 t_last = first;
		size_t cmp_len = distance(first, last) - distance(s_first, s_last) + 1;
		advance(t_last, cmp_len);

		for (; first != t_last; ++first)
		{
			ForwardIterator1 iter = first;
			ForwardIterator2 s_iter = s_first;
			while (pred(*iter, *s_iter))
			{
				++iter;
				++s_iter;

				if (iter == s_iter)
					return first;
			}
		}
		return last;
	}

	/*!
	 *	copy()
	 *
	 *	\brief	범위 복사
	 */
	template<typename InputIterator, typename OutputIterator>
	OutputIterator copy(InputIterator first, InputIterator last, OutputIterator dest);

	/*!
	 *	copy_if()
	 *
	 *	\brief	범위 내의 조건을 만족하는 요소를 다른 곳에 복사함
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
	OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred);

	/*!
	 *	copy_n()
	 *
	 *	\brief	지정한 위치에서 n개의 요소를 복사
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename Size, class OutputIterator>
	OutputIterator copy_n(InputIterator first, Size count, OutputIterator result);

	/*!
	 *	copy_backward()
	 *
	 *	\brief	역방향으로 범위 복사
	 */
	template<typename BidirectionalIterator1, typename BidirectionalIterator2>
	BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result);

	/*!
	 *	fill()
	 *
	 *	\brief	범위 내를 값으로 채움
	 */
	template<typename ForwardIterator, typename T>
	void fill(ForwardIterator first, ForwardIterator last, const T& value);

	/*!
	 *	fill_n()
	 *
	 *	\brief
	 */
	template<typename OutputIterator, class Size, class T>
	OutputIterator fill_n(OutputIterator first, Size count, const T& value);

	/*!
	 *	count()
	 *
	 *	\brief	범위 내에 특정 값을 가진 개체의 수를 조사
	 */
	template<typename InputIterator, typename T>
	ptrdiff_t count(InputIterator first, InputIterator last, const T& value)
	{
		ptrdiff_t ret = 0;
		while (first != last)
		{
			if (*first == value)
				++ret;

			++first;
		}
		return ret;
	}

	/*!
	 *	count_if()
	 */
	template <typename InputIterator, typename Predicate>
	ptrdiff_t count_if(InputIterator first, InputIterator last, Predicate pred)
	{
		ptrdiff_t ret = 0;
		while (first != last)
		{
			if (pred(*first))
				++ret;

			++first;
		}
		return ret;
	}

	/*!
	 *	mismatch()
	 *
	 */
	template<typename InputIterator1, typename InputIterator2>
	pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (*first1 != *first2)
				break;
		}
		return make_pair(first1, first2);
	}

	template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first, InputIterator1 last, InputIterator2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!pred(*first1, *first2))
				break;
		}
		return make_pair(first1, first2);
	}

	/*!
	 *	equal()
	 */
	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);

	template <typename ForwardIterator, typename T>
	pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& value)
	{
		ForwardIterator it = lower_bound(first, last, value);
		return make_pair(it, upper_bound(it, last, value));
	}

	/*!
	 *	partition()
	 *
	 *	\brief	범위내의 요소들을 분할
	 *	\note	C++11에서는 양방향이 아니라 전방향반복자로 바뀜... 일단 지금은 무시하자
	 */
	template<typename BidirectionalIterator, class UnaryPredicate>
	BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred)
	{
		while (true)
		{
			while ((first != last) && pred(*first))
				++first;			// 조건을 만족하지 않는 요소를 검색
			if (first == last--)
				break;				// 그게 마지막 요소면 분할 끝

			while ((first != last) && !p(*last))
				--last;				// 조건을 만족하는 요소를 뒷쪽에서부터 검색
			if (first == last)
				break;				// 위에서 찾은 요소까지 달리 없으면 분할 끝

			swap(*first, *last);	// 두 요소를 스왑
			++first;
		}
		return first;
	}

	/*!
	 *	is_partitioned()
	 *
	 *	\brief	범위 내의 요소들이 주어진 조건에 따라 분할되어 있는지 검증
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename UnaryPredicate>
	bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		for (; first != last; ++first)
			if (!pred(*first))		// 조건을 만족하지 않는곳(분할경계)까지 이동
				break;

		for (; first != last; ++first)
			if (pred(*first))		// 경계를 넘어섰는데 조건을 만족하면 제대로 분할되지 않은 것
				return false;

		return true;
	}

	/*!
	 *	partition_copy()
	 *
	 *	\brief	특정 범위의 요소를 주어진 조건에 따라 분할하여 지정한 곳에 각각 복사함
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename OutputIterator1, typename OutputIterator2, typename UnaryPredicate>
	pair<OutputIterator1, OutputIterator2> partition_copy(InputIterator first, InputIterator last, OutputIterator1 result_true, OutputIterator2 result_false, UnaryPredicate pred)
	{
		while (first != last)
		{
			if (pred(*first))
			{
				*result_true = *first;
				++result_true;
			}
			else
			{
				*result_false = *first;
				++result_false;
			}
			++first;
		}
		return pair<OutputIterator1, OutputIterator2>(result_true, result_false);
	}

	/*!
	 *	all_of()
	 *
	 *	\brief	범위 내의 요소들이 모두 조건을 만족하는지 확인
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename UnaryPredicate>
	bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred);

	/*!
	 *	any_of()
	 *
	 *	\brief	범위 내에서 조건을 만족하는 것이 있는지 확인
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename UnaryPredicate>
	bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred);

	/*!
	 *	none_of()
	 *
	 *	\brief	범위 내에서 요소들이 모두 조건을 만족하지 않는지 확인
	 *	\note	C++11에서 추가됨
	 */
	template<typename InputIterator, typename UnaryPredicate>
	bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred);

	/*!
	*	is_sorted_until()
	*
	*	\brief	범위 내의 요소들중 정렬되어 있는 마지막 반복자를 돌려줌
	*	\note	C++11에서 추가됨
	*/
	template<typename ForwardIterator>
	ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last);

	template<typename ForwardIterator, typename Compare>
	ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last, Compare comp);

	/*!
	 *	is_sorted()
	 *
	 *	\brief	범위 내의 요소들이 정렬되어 있는지 확인
	 *	\note	C++11에서 추가됨
	 */
	template<typename ForwardIterator>
	bool is_sorted(ForwardIterator first, ForwardIterator last);

	template<typename ForwardIterator, typename Compare>
	bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp);

	/**
	 *	transform
	 *
	 *	\brief	범위 내의 원소를 변경하여 출력
	 */
	template<typename InputIterator, typename OutputIterator, typename UnaryOperation>
	OutputIterator transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op);

	template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperation>
	OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation op);

	/**
	 *	generate
	 *
	 *	\brief	지정한 식을 사용하여 생성된 값을 범위에 할당
	 */
	template<typename ForwardIterator, typename Generator>
	void generate(ForwardIterator first, ForwardIterator last, Generator gen);

	/**
	 *	generate_n
	 *
	 *	\brief	지정한 식을 사용하여 생성된 값을 범위 내에 할등.
	 */
	template<typename ForwardIterator, typename Size, typename Generator>
	void generate_n(ForwardIterator first, Size num, Generator gen);

	/**
	 *	replace
	 *
	 *	\brief	범위 내 원소의 값을 다른 것으로 교체
	 */
	template<typename ForwardIterator, typename T>
	void replace(ForwardIterator first, ForwardIterator last, const T& old_val, const T& new_val);

	/**
	*	replace_if
	*
	*	\brief	범위 내 원소의 값을 다른 것으로 교체
	*/
	template<typename ForwardIterator, typename UnaryPredicate, typename T>
	void replace_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_val);

	/**
	 *	replace_copy
	 *
	 *	\brief	범위 내의 원소를 다른 범위로 교체하면서 복사
	 */
	template<typename InputIterator, typename OutputIterator, typename T>
	OutputIterator replace_copy(InputIterator first, InputIterator last, OutputIterator result, const T& old_val, const T& new_val);

	template<typename InputIterator, typename OutputIterator, typename UnaryPredicate, typename T>
	OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred, const T& new_val);

#include "algorithm.inl"

}	// namespace Mh

#endif	/* _MH_STL_ALGORITHM_HPP_ */