#ifndef _MH_NUMERIC_HPP_
#define _MH_NUMERIC_HPP_

namespace Mh
{
	template<typename InputIterator, typename T>
	T accumulate(InputIterator first, InputIterator last, T init);

	template<typename InputIterator, typename T, typename BinaryOperation>
	T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation op);

	template<typename InputIterator1, typename InputIterator2, typename T>
	T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init);

	template<typename InputIterator1, typename InputIterator2, typename T, typename BinaryOperation1, typename BinaryOperation2>
	T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryOperation1 op1, BinaryOperation2 op2);

	template<typename InputIterator, typename OutputIterator>
	OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result);

	template<typename InputIterator, typename OutputIterator, typename BinaryOperation>
	OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op);

	template<typename InputIterator, typename OutputIterator>
	OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result);

	template<typename InputIterator, typename OutputIterator, typename BinaryOperation>
	OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op);

	template<typename InputIterator, typename T>
	void iota(InputIterator first, InputIterator last, T val);

#include "numeric.inl"
}

#endif // !_MH_NUMERIC_HPP_
