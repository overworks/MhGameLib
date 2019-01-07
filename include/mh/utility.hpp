#ifndef	_MH_UTILITY_HPP_
#define	_MH_UTILITY_HPP_

namespace Mh
{
	template<typename T1, typename T2>
	struct pair
	{
		typename	T1	first_type;
		typename	T2	second_type;

		T1	first;
		T2	second;

		pair() : first(T1()), second(T2()) {}
		pair(const T1& x, const T2& y) : first(x), second(y) {}
		template<typename U, typename V> pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
	};

	template<typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}
}

#endif	/* _MH_UTILITY_HPP_ */