#ifndef	_MH_PREREQUISTITE_H_
#define	_MH_PREREQUISTITE_H_

#include "predef/language.h"
#include "predef/platform.h"
#include "predef/compiler.h"
#include "predef/architecture.h"
#include "predef/config.h"

#if		((_MH_PLATFORM_ == _MH_PLATFORM_WIN32_) || (_MH_PLATFORM_ == _MH_PLATFORM_WIN64_)) && defined(_USRDLL)
#	ifdef	_MH_EXPORT_DLL_
#		define	MH_API		__declspec(dllexport)
#		define	MH_CLASS	__declspec(dllexport)
#		define	MH_TEMPLATE
#	else
#		define	MH_API		__declspec(dllimport)
#		define	MH_CLASS	__declspec(dllimport)
#		define	MH_TEMPLATE	extern
#	endif
#else
#	define	MH_API
#	define	MH_CLASS
#	define	MH_TEMPLATE
#endif

#if		(_MH_PLATFORM_ == _MH_PLATFORM_WIN32_) || (_MH_PLATFORM_ == _MH_PLATFORM_WIN64_)
#	define	_MH_COMPILE_DIRECTX_
#endif

#if !(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_OVERRIDE_FINAL_)

#define	override
#define	final

#endif	// !(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_OVERRIDE_FINAL_)

#if		!defined(_MH_DEBUG_) && (defined(_DEBUG))
#	define	_MH_DEBUG_
#endif

#endif	/* _MH_PREREQUISTITE_H_ */