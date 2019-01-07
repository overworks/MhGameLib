#ifndef	_MH_PREDEF_PLATFORM_H_
#define	_MH_PREDEF_PLATFORM_H_

/* platform
 *
 *	_MH_PLATFORM_WIN32_
 *	_MH_PLATFORM_WIN64_
 *	_MH_PLATFORM_OSX_
 *	_MH_PLATFORM_LINUX_
 *	_MH_PLATFORM_XENON_ (a.k.a XBox2)
 *	_MH_PLATFORM_PS3_
 */

#define	_MH_PLATFORM_WIN32_		(1)
#define	_MH_PLATFORM_WIN64_		(2)
#define	_MH_PLATFORM_OSX_		(3)
#define	_MH_PLATFORM_LINUX_		(4)
#define	_MH_PLATFORM_XENON_		(5)
#define	_MH_PLATFORM_PS3_		(6)

#if		defined(_WIN32)
#	if		defined(_WIN64)
#		define	_MH_PLATFORM_	_MH_PLATFORM_WIN64_
#	else
#		define	_MH_PLATFORM_	_MH_PLATFORM_WIN32_
#	endif
#endif

#endif	/* _MH_PREDEF_PLATFORM_H_ */