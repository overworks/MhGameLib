#ifndef	_MH_PREDEF_LANGUAGE_H_
#define	_MH_PREDEF_LANGUAGE_H_

/*
 *	language
 */

#define	_MH_CPP11_FEATURE_AUTO_					(1 << 0)
#define	_MH_CPP11_FEATURE_DECLTYPE_				(1 << 1)
#define	_MH_CPP11_FEATURE_NULLPTR_				(1 << 2)
#define	_MH_CPP11_FEATURE_LAMBDA_				(1 << 3)
#define	_MH_CPP11_FEATURE_CONSTEXPR_			(1 << 4)
#define	_MH_CPP11_FEATURE_RVALUE_REFERENCE_		(1 << 5)
#define	_MH_CPP11_FEATURE_STATIC_ASSERT_		(1 << 6)
#define _MH_CPP11_FEATURE_RANGE_BASED_FOR_LOOP_	(1 << 7)
#define	_MH_CPP11_FEATURE_OVERRIDE_FINAL_		(1 << 8)
#define	_MH_CPP11_FEATURE_INLINE_NAMESPACE_		(1 << 9)
#define	_MH_CPP11_FEATURE_INITIALIZER_LIST_		(1 << 10)
#define	_MH_CPP11_FEATURE_DEFAULTED_DELETED_	(1 << 11)

#if		defined(__cplusplus)
#	if		__cplusplus == 199711L
#		define	_MH_CPP_VER_	98
#	elif	__cplusplus == 201103L
#		define	_MH_CPP_VER_	11
#	endif
#else
#	error	MhLib needs C++ compiler.
#endif

#endif	/* _MH_PREDEF_LANGUAGE_H_ */