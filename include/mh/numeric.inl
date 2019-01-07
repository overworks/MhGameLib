#ifndef _MH_NUMERIC_INL_
#define _MH_NUMERIC_INL_

template<typename InputIterator, typename T>
T accumulate(InputIterator first, InputIterator last, T init)
{
	while (first != last)
	{
		init = init + *first;
		++first;
	}
	return first;
}

template<typename InputIterator, typename T, typename BinaryOperation>
T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation op)
{
	while (first != last)
	{
		init = op(init, *first);
		++first;
	}
	return first;
}

template<typename InputIterator1, typename InputIterator2, typename T>
T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init)
{
	while (first1 != last1)
	{
		init = init + (*first1 * *first2);
		++first1; ++first2;
	}
	return init;
}

template<typename InputIterator1, typename InputIterator2, typename T, typename BinaryOperation1, typename BinaryOperation2>
T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryOperation1 op1, BinaryOperation2 op2)
{
	while (first1 != last1)
	{
		init = op1(init, op2(*first1, *first2));
		++first1; ++first2;
	}
	return init;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result)
{
	if (first != last)
	{
		typename iterator_traits<InputIterator>::value_type val = *first;
		*result = val;
		++first;
		while (first != last)
		{
			val = val + *first;
			++first; 
			++result;
			*result = val;
		}
		++result;
	}
	return result;
}

template<typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op)
{
	if (first != last)
	{
		typename iterator_traits<InputIterator>::value_type val = *first;
		*result = val;
		++first;
		while (first != last)
		{
			val = op(val, *first);
			++first;
			++result;
			*result = val;
		}
		++result;
	}
	return result;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result)
{
	if (first != last)
	{
		typename iterator_traits<InputIterator>::value_type val, prev;
		*result = prev = *first;
		++first;
		while (first != last)
		{
			val = *first;
			++first;
			++result;
			*result = val - prev;
			prev = val;
		}
		++result;
	}
	return result;
}

template<typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op)
{
	if (first != last)
	{
		typename iterator_traits<InputIterator>::value_type val, prev;
		*result = prev = *first;
		++first;
		while (first != last)
		{
			val = *first;
			++first;
			++result;
			*result = op(val, prev);
			prev = val;
		}
		++result;
	}
	return result;
}

template<typename InputIterator, typename T>
void iota(InputIterator first, InputIterator last, T val)
{
	while (first != last)
	{
		*first = val;
		++result; ++val;
	}
}

#endif // !_MH_NUMERIC_INL_