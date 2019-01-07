#ifndef	_MH_STL_FUNCTIONAL_HPP_
#define	_MH_STL_FUNCTIONAL_HPP_

namespace Mh
{
	/*
	 *	단항 함수객체 기본 클래스
	 */
	template<typename Arg, typename Result>
	struct unary_funciton
	{
		typedef Arg		argument_type;
		typedef Result	result_type;
	};

	/*
	 *	이항 함수객체 기본 클래스
	 */
	template<typename Arg1, typename Arg2, typename Result>
	struct binary_function
	{
		typedef	Arg1	first_argument_type;
		typedef	Arg2	second_argument_type;
		typedef	Result	result_type;
	};

	template<typename T>
	struct greater : binary_function<T, T, bool>
	{
		bool operator() ( const T& l, const T& r ) const
		{
			return l > r;
		}
	};

	template<typename T>
	struct greater_equal : binary_function<T, T, bool>
	{
		bool operator() ( const T& l, const T& r ) const
		{
			return l >= r;
		}
	};

	template<typename T>
	struct less : binary_function<T, T, bool>
	{
		bool operator() ( const T& l, const T& r ) const
		{
			return l < r;
		}
	};

	template<typename T>
	struct less_equal : binary_function<T, T, bool>
	{
		bool operator() ( const T& l, const T& r ) const
		{
			return l <= r;
		}
	};

}		// namespace Mh

#endif	/* _MH_STL_FUNCTIONAL_HPP_ */