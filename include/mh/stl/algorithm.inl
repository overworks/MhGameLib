#ifndef _MH_STL_ALGORITHUM_INL_
#define	_MH_STL_ALGORITHUM_INL_

#ifndef min
template<typename T>
const T& min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template<typename T, typename Compare>
const T& min(const T& a, const T& b, Compare comp)
{
	return comp(a, b) ? a : b;
}
#endif // !min

template<typename ForwardIterator>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
{
	if (first == last)
		return last;

	ForwardIterator lowest = first;
	while (++first != last)
		if (*first < *lowest)
			lowest = first;
	return lowest;
}

template<typename ForwardIterator, typename Compare>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp)
{
	if (first == last)
		return last;

	ForwardIterator lowest = first;
	while (++first != last)
		if (comp(*first, *lowest))
			lowest = first;
	return lowest;
}

#ifndef max
template<typename T>
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}

template<typename T, typename Compare>
const T& max(const T& a, const T& b, Compare comp)
{
	return comp(a, b) ? b : a;
}
#endif // !max

template<typename ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
{
	ForwardIterator largest = first;
	if (first == last) return last;
	while (++first != last)
		if (*largest < *first)
			largest = first;
	return largest;
}

template<typename ForwardIterator, typename Compare>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last, Compare comp)
{
	ForwardIterator largest = first;
	if (first == last) return last;
	while (++first != last)
		if (comp(*largest, *first))
			largest = first;
	return largest;
}

template<typename T>
pair<const T&, const T&> minmax(const T& a, const T& b)
{
	return (b < a ? make_pair(b, a) : make_pair(a, b));
}

template<typename T, typename Compare>
pair<const T&, const T&> minmax(const T& a, const T& b, Compare comp)
{
	return (comp(b, a) ? make_pair(b, a) : make_pair(a, b));
}

template<typename T>
const T& clamp(const T& val, const T& lo, const T& hi)
{
	return val < lo ? lo : hi < val ? hi : val;
}

template<typename T, typename Compare>
const T& clamp(const T& val, const T& lo, const T& hi, Compare comp)
{
	return comp(val, lo) ? lo : comp(hi, val) ? hi : val;
}

template<typename T>
void swap(T& a, T& b)
{
	T temp(b);
	b = a;
	a = temp;
}

template<typename ForwardIterator1, typename ForwardIterator2>
void iter_swap(ForwardIterator1 a, ForwardIterator2 b)
{
	swap(*a, *b);
}

template<typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)
{
	while (first1 != last1)
		iter_swap(first1++, first2++);
	return first1;
}

template<typename BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last)
{
	while ((first != last) && (first != --last))
		swap(*first++, *last);
}

template<typename BidirectionalIterator, typename OutputIterator>
OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator dest)
{
	while ((first != last) && (first != --last))
		*dest++ = *last;
}

template<typename ForwardIterator>
ForwardIterator rotate(ForwardIterator first, ForwardIterator n_first, ForwardIterator last)
{
	ForwardIterator next = n_first;
	while (first != last)
	{
		swap(*first, *next);
		++first, ++next;
		if (next == last)
			next = n_first;
		else if (first == n_first)
			n_first = next;
	}
	return first;
}

template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& value)
{
	for (; first != last; ++first)
		if (*first == value) break;
	return first;
}

template<typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred)
{
	for (; first != last; ++first)
		if (pred(*first)) break;
	return first;
}

template<typename InputIterator, typename UnaryPredicate>
InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
{
	for (; first != last; ++first)
		if (!pred(*first)) break;
	return first;
}

template<typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
	if (first2 == last2)
		return last1;  // specified in C++11

	ForwardIterator1 ret = last1;
	while (first1 != last1)
	{
		ForwardIterator1 it1 = first1;
		ForwardIterator2 it2 = first2;
		while (*it1 == *it2)
		{
			++it1; ++it2;
			if (it2 == last2) { ret = first1; break; }
			if (it1 == last1) return ret;
		}
		++first1;
	}
	return ret;
}

template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)
{
	if (first2 == last2)
		return last1;  // specified in C++11

	ForwardIterator1 ret = last1;

	while (first1 != last1)
	{
		ForwardIterator1 it1 = first1;
		ForwardIterator2 it2 = first2;
		while (pred(*it1, *it2))
		{
			++it1; ++it2;
			if (it2 == last2) { ret = first1; break; }
			if (it1 == last1) return ret;
		}
		++first1;
	}
	return ret;
}

template<typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
	for (; first1 != last1; ++first1)
		for (ForwardIterator2 it = first2; it != last2; ++it)
			if (*it == *first1)
				return first1;
	return last1;
}

template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)
{
	for (; first1 != last1; ++first1)
		for (ForwardIterator2 it = first2; it != last2; ++it)
			if (pred(*it, *first1))
				return first1;
	return last1;
}

template<typename InputIterator, typename UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
{
	return find_if_not(first, last, pred) == last;
}

template<typename InputIterator, typename UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred)
{
	return find_if(first, last, pred) != last;
}

template<typename InputIterator, typename UnaryPredicate>
bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred)
{
	return find_if(first, last, pred) == last;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator dest)
{
	while (first != last)
	{
		*dest = *first;
		++first, ++dest;
	}
	return dest;
}

template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred)
{
	while (first != last)
	{
		if (pred(first))
		{
			*last = *first;
			++last;
		}
		++first;
	}
	return result;
}

template<typename InputIterator, typename Size, class OutputIterator>
OutputIterator copy_n(InputIterator first, Size count, OutputIterator result)
{
	// count <= 0 일때는 아무것도 하지 않음
	if (count > 0)
	{
		*result++ = *first;
		for (Size i = 1; i < count; ++i)
		{
			*result = *(++first);
			++result;
		}
	}
	return result;
}

template<typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result)
{
	while (last != first)
		*(--result) = *(--last);
	return result;
}

template<typename ForwardIterator, typename T>
void fill(ForwardIterator first, ForwardIterator last, const T& value)
{
	for (; first != last; ++first)
		*first = value;
}

template<typename OutputIterator, class Size, class T>
OutputIterator fill_n(OutputIterator first, Size count, const T& value)
{
	for (Size i = 0; i < count; ++i)
		*first++ = value;
	return first;
}

template<typename InputIterator, typename OutputIterator, typename UnaryOperation>
OutputIterator transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op)
{
	while (first1 != last1)
	{
		*result = op(*first1);
		++first1; ++result;
	}
	return result;
}

template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperation>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation op)
{
	while (first1 != last1)
	{
		*result = op(*first1, first2);
		++first1; ++first2; ++result;
	}
	return result;
}

template<typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen)
{
	while (first != last)
	{
		*first = gen();
		++first;
	}
}

template<typename ForwardIterator, typename Size, typename Generator>
void generate_n(ForwardIterator first, Size num, Generator gen)
{
	while (num > 0)
	{
		*first = gen();
		++first;
		--num;
	}
}

template<typename ForwardIterator, typename T>
void replace(ForwardIterator first, ForwardIterator last, const T& old_val, const T& new_val)
{
	while (first != last)
	{
		if (*first == old_val)
			*first = new_val;
		++first;
	}
}

template<typename ForwardIterator, typename UnaryPredicate, typename T>
void replace_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_val)
{
	while (first != last)
	{
		if (pred(*first))
			*first = new_val;
		++first;
	}
}

template<typename InputIterator, typename OutputIterator, typename T>
OutputIterator replace_copy(InputIterator first, InputIterator last, OutputIterator result, const T& old_val, const T& new_val)
{
	while (first != last)
	{
		*result = (*first == old_val) ? new_val : *first;
		++first;
		++result;
	}
	return result;
}

template<typename InputIterator, typename OutputIterator, typename UnaryPredicate, typename T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred, const T& new_val)
{
	while (first != last)
	{
		*result = pred(*first) ? new_val : *first;
		++first;
		++result;
	}
	return result;
}

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return false;

		++first1;
		++first2;
	}
	return true;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return false;

		++first1;
		++first2;
	}
	return true;
}

template<typename ForwardIterator>
ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last)
{
	if (first == last)
		return first;

	for (ForwardIterator next = first; ++next != last; ++first)
	{
		if (*next < *first)
			return next;
	}

	return last;
}

template<typename ForwardIterator, typename Compare>
ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last, Compare comp)
{
	if (first == last)
		return first;

	for (ForwardIterator next = first; ++next != last; ++first)
	{
		if (comp(*next, *first))
			return next;
	}

	return last;
}

template<typename ForwardIterator>
bool is_sorted(ForwardIterator first, ForwardIterator last)
{
	return is_sorted_until(first, last) == last;
}

template<typename ForwardIterator, typename Compare>
bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp)
{
	return is_sorted_until(first, last, comp) == last;
}

#endif // !_MH_STL_ALGORITHUM_INL_