#ifndef	_MH_STL_ARRAY_HPP_
#define	_MH_STL_ARRAY_HPP_

#include <array>
#include <mh/types.hpp>
#include "type_traits.hpp"
#include "iterator.hpp"
#include "algorithm.hpp"

/*
 *	C++11(tr1)에서 추가된 array 컨테이너 구현
 */
namespace Mh
{
	template<typename T, Mh::size_t N>
	struct array
	{
	public:
		// 이하 타입 재정의
		typedef	Mh::size_t		size_type;
		typedef	Mh::ptrdiff_t	difference_type;
		typedef	T				value_type;
		typedef	T&				reference;
		typedef	const T&		const_reference;
		typedef	T*				pointer;
		typedef	const T*		const_pointer;
		typedef	pointer			iterator;
		typedef	const_pointer	const_iterator;
		typedef	Mh::reverse_iterator<iterator>			reverse_iterator;
		typedef	Mh::reverse_iterator<const_iterator>	const_reverse_iterator;

		static const size_type static_size = N;

		// 이하 멤버 함수
		template<typename U> array& operator = ( const array<U,N>& );

		void	fill( const_reference value );
		void	assign( const T& value );
		void	swap( array& other );
#if		(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_RVALUE_REFERENCE_)
		void	swap( array&& other );
#endif

		reference		at( size_type pos );
		const_reference	at( size_type pos ) const;
		reference		front();
		const_reference	front() const;
		reference		back()			{ return arr[N-1]; }
		const_reference	back() const	{ return arr[N-1]; }
		pointer			data()			{ return arr; }
		const_pointer	data() const	{ return arr; }

		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
		
#if		(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_CONSTEXPR_)
		constexpr bool		empty() const		{ return false; }
		constexpr size_type	size() const		{ return N; }
		constexpr size_type	max_size() const	{ return N; }
#else
		bool				empty() const		{ return false; }
		size_type			size() const		{ return N; }
		size_type			max_size() const	{ return N; }
#endif

		reference		operator []	( size_type pos );
		const_reference	operator []	( size_type pos ) const;

	private:
		T	arr[N];
	};

	// N == 0일때를 대비한 특수화
	template<typename T>
	struct array<T, 0>
	{
	public:
		// 이하 타입 재정의
		typedef	Mh::size_t		size_type;
		typedef	Mh::ptrdiff_t	difference_type;
		typedef	T				value_type;
		typedef	T&				reference;
		typedef	const T&		const_reference;
		typedef	T*				pointer;
		typedef	const T*		const_pointer;
	};

	// 함수 템플릿
	template <typename T, size_t N>	bool operator ==	( const array<T, N>& l, const array<T, N>& r );
	template <typename T, size_t N>	bool operator !=	( const array<T, N>& l, const array<T, N>& r );
	template <typename T, size_t N>	bool operator <		( const array<T, N>& l, const array<T, N>& r );
	template <typename T, size_t N>	bool operator <=	( const array<T, N>& l, const array<T, N>& r );
	template <typename T, size_t N>	bool operator <		( const array<T, N>& l, const array<T, N>& r );
	template <typename T, size_t N>	bool operator >=	( const array<T, N>& l, const array<T, N>& r );
	template <typename T, size_t N>	bool operator >		( const array<T, N>& l, const array<T, N>& r );

	template <typename T, size_t N>	void swap	( array<T, N>& l, array<T, N>& r );

	template <int I, typename T, size_t N>	T&			get( array<T, N>& arr );
	template <int I, typename T, size_t N>	const T&	get( const array<T, N>& arr );

	// 헬퍼 클래스
//	template <typename T, size_t N>	class tuple_element< array<T, N> >;
//	template <typename T, size_t N>	class tuple_size< array<T, N> >;
//	template<typename T, size_t N>
//	class tuple_size< array<T,N> > : public intergral_constant<size_t, N>
//	{};


#include "array.inl"
}

#endif	/* _MH_STL_ARRAY_HPP_ */