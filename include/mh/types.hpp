#pragma		once
#ifndef		_MH_TYPE_HPP_
#define		_MH_TYPE_HPP_

#include <cstddef>
#include <mh/prerequisite.h>

/*!
 *	Base Type
 *	기본 타입
 */

 // 컴파일러가 nullptr을 지원하지 않을때
#if	!(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_NULLPTR_)

const class {
public:
	// 포인터 요구시 0을 돌려줌
	template<typename T> operator T* () const { return 0; }
	template<typename C, typename T> operator T C::*() const { return 0; }

private:
	// 참조 연산자를 정의하지 않았으므로 참조하려 하면 컴파일 에러
	void operator& () const;

} nullptr = {};

#endif	// #if	!(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_NULLPTR_)

namespace	Mh
{	
	using ::size_t;
	using ::ptrdiff_t;
	
#if		_MH_COMPILER_ == _MH_COMPILER_MSVC_
	typedef		signed __int8		s8;
	typedef		signed __int16		s16;
	typedef		signed __int32		s32;
	typedef		signed __int64		s64;
	typedef		unsigned __int8		u8;
	typedef		unsigned __int16	u16;
	typedef		unsigned __int32	u32;
	typedef		unsigned __int64	u64;
#elif	_MH_ACHITECTURE_ == _MH_ACHITECTURE_X86_64_
	typedef		signed char			s8;
	typedef		signed short		s16;
	typedef		signed int			s32;
	typedef		signed long			s64;
	typedef		unsigned char		u8;
	typedef		unsigned short		u16;
	typedef		unsigned int		u32;
	typedef		unsigned long		u64;
#else
	typedef		signed char			s8;
	typedef		signed short		s16;
	typedef		signed long			s32;
	typedef		signed long long	s64;
	typedef		unsigned char		u8;
	typedef		unsigned short		u16;
	typedef		unsigned long		u32;
	typedef		unsigned long long	u64;
#endif
	typedef		float				f32;
	typedef		double				f64;

#if	!defined(_XBOX360_) && !defined(_X64_)
	typedef		s32		sint;
	typedef		u32		uint;
#else
	typedef		s64		sint;
	typedef		u64		uint;
#endif

//	typedef		u16		f16;	// 이건 어떻게 구현해야할지 모르겠다... 일단 코멘트 아웃

#if		_MH_CONFIG_PRECISION_ == _MH_CONFIG_PRECISION_DOUBLE_
	typedef		f64		real;
#elif	_MH_CONFIG_PRECISION_ == _MH_CONFIG_PRECISION_HALF_
	typedef		f16		real;
#else
	typedef		f32		real;
#endif

	typedef		signed char		schar;
	typedef		signed short	sshort;
	typedef		signed long		slong;
	typedef		unsigned char	uchar;
	typedef		unsigned short	ushort;
	typedef		unsigned long	ulong;

	union Universal
	{
		s32		s;
		u32		u;
		f32		f;
	};

	class Result
	{
	public:
		Result()
			: m_code(0)			{}
		Result( sint s )
			: m_code( s )		{}

		operator bool()	const	{ return succeeded();	}
		operator sint() const	{ return m_code;		}

		bool succeeded() const	{ return m_code > 0;	}
		bool failed() const		{ return m_code <= 0;	}

	private:
		sint				m_code;
	};
};

#endif		/* _MH_TYPE_HPP_ */