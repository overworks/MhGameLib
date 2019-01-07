#ifndef	_MH_STL_TYPE_TRAITS_HPP_
#define	_MH_STL_TYPE_TRAITS_HPP_

#include <mh/prerequisite.h>
//#include <type_traits>

/*!
 *	C++11(TR1)에서 추가된 헤더 구현
 */
namespace Mh
{
	template<typename T, T v>
	struct integral_constant
	{
		typedef	T						value_type;
		typedef	integral_constant<T,v>	type;

#if	(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_CONSTEXPR_)
		static constexpr T value = v;
#else
		static T value = v;
#endif	// ifdef _MH_COMPILER_SUPPORT_CONSTEXPR_
	};

	typedef	integral_constant<bool, true>	true_type;
	typedef	integral_constant<bool, false>	false_type;

	template<typename T> struct	is_void;
	template<typename T> struct	is_integral;
	template<typename T> struct	is_floating_point;
	template<typename T> struct	is_array;
	template<typename T> struct	is_pointer;
	template<typename T> struct	is_reference;
	template<typename T> struct	is_member_object_pointer;
	template<typename T> struct	is_member_function_pointer;
	template<typename T> struct	is_enum;
	template<typename T> struct	is_union;
	template<typename T> struct	is_class;
	template<typename T> struct	is_function;

	template<typename T> struct	is_arithmetic;
	template<typename T> struct	is_fundamental;
	template<typename T> struct	is_object;
	template<typename T> struct	is_scalar;
	template<typename T> struct	is_compound;
	template<typename T> struct	is_member_pointer;

	template<typename T> struct	is_const;
	template<typename T> struct	is_volatile;
	template<typename T> struct	is_pod;
	template<typename T> struct	is_empty;
	template<typename T> struct	is_polymorphic;
	template<typename T> struct	is_abstract;
	template<typename T> struct	has_trivial_constructor;
	template<typename T> struct	has_trivial_copy;
	template<typename T> struct	has_trivial_assign;
	template<typename T> struct	has_trivial_destructor;
	template<typename T> struct	has_nothrow_construct;
	template<typename T> struct	has_nothrow_copy;
	template<typename T> struct	has_nothrow_assign;

	template<typename T> struct	has_virtual_destructor;
	template<typename T> struct	is_signed;
	template<typename T> struct	is_unsigned;
	template<typename T> struct	rank;
	template<typename T, unsigned I = 0> struct extent;

	template<typename T1, typename T2> struct is_same;
	template<typename From, class To> struct is_convertible;
	template<typename Base, class Derived> struct is_base_of;
	
	template<typename T> struct	remove_const;
	template<typename T> struct	remove_volatile;
	template<typename T> struct	remove_cv;
	template<typename T> struct	add_const;
	template<typename T> struct	add_volatile;
	template<typename T> struct	add_cv;
	template<typename T> struct	remove_reference;
	template<typename T> struct	add_reference;
	template<typename T> struct	remove_pointer;
	template<typename T> struct	add_pointer;
	template<typename T> struct	remove_extent;
	template<typename T> struct	remove_all_extents;

	template<typename T> struct	alignment_of;
	template<size_t L, size_t A> struct aligned_storage;

}		// namespace Mh

#endif	/* _MH_STL_TYPE_TRAITS_HPP_ */