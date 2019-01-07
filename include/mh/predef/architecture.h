#ifndef	_MH_PREDEF_ARCHITECTURE_H_
#define	_MH_PREDEF_ARCHITECTURE_H_

/* architecture
 *
 *	_MH_ARCHITECTURE_X86_	
 *	_MH_ARCHITECTURE_X86_64_
 *	_MH_ARCHITECTURE_ARM_
 *	_MH_ARCHITECTURE_ARM64_
 *	_MH_ARCHITECTURE_PPC_
 *	_MH_ARCHITECTURE_PPC64_
 */

#define	_MH_ARCHITECTURE_X86_		(1)
#define	_MH_ARCHITECTURE_X86_64_	(2)
#define	_MH_ARCHITECTURE_ARM_		(3)
#define	_MH_ARCHITECTURE_ARM64_		(4)
#define	_MH_ARCHITECTURE_PPC_		(5)
#define	_MH_ARCHITECTURE_PPC64_		(6)

#if		defined(_M_AMD64) || defined(_M_X64) || defined(__amd64__)
#	define	_MH_ARCHITECTURE_	_MH_ARCHITECTURE_X86_64_
#elif	defined(_M_IX86) || defined(__i386__)
#	define	_MH_ARCHITECTURE_	_MH_ARCHITECTURE_X86_
#elif	defined(_M_ARM64)
#	define	_MH_ARCHITECTURE_	_MH_ARCHITECTURE_ARM64_
#elif	defined(__arm__)
#	define	_MH_ARCHITECTURE_	_MH_ARCHITECTURE_ARM_
#elif	defined(__ppc64__)
#	define	_MH_ARCHITECTURE_	_MH_ARCHITECTURE_PPC64_
#elif	defined(__ppc__)
#	define	_MH_ARCHITECTURE_	_MH_ARCHITECTURE_PPC_
#endif

/*
 *	엔디안 관련
 */
#define	_MH_ENDIAN_SMALL_		(0)
#define	_MH_ENDIAN_BIG_			(1)
#define	_MH_ENDIAN_SMALL_WORD_	(2)
#define	_MH_ENDIAN_BIG_WORD_	(3)


#endif	/* _MH_PREDEF_ARCHITECTURE_H_ */