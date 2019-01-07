#ifndef	_MH_UTIL_HPP_
#define	_MH_UTIL_HPP_

#include	<cassert>
#include	"pattern.hpp"

#define		MH_STATIC_ASSERT(b)		Mh::StaticAssertFailure<b>()

namespace Mh
{
	/*!
	 *	\brief	静的アサーション(From BOOST_STATIC_ASSERT)
	 */
	template <bool b> struct StaticAssertFailure;
	template <> struct StaticAssertFailure<true> {};

	/*!
	 *	\brief	SafeDelete
	 */
	template <typename T>
	inline void SafeDelete( T** pInstance )
	{
		if ( *pInstance )
		{
			delete *pInstance;
			*pInstance = 0;
		}
	}

	/*!
	 *	\brief	SafeDelete(配列ver)
	 */
	template <typename T>
	inline void SafeDeleteArray( T** pInstanceArray )
	{
		if ( *pInstanceArray )
		{
			delete[] *pInstanceArray;
			*pInstanceArray = 0;
		}
	}

	/*!
	 *	\brief	SafeRelease(COM)
	 */
	template <typename COM>
	inline unsigned long SafeRelease( COM** ppInterface )
	{
		unsigned long ret = 0;
		if ( *ppInterface )
		{
			ret = (*ppInterface)->Release();
			*ppInterface = 0;
		}
		return ret;
	}

	/*!
	 *	\brief		削除functor
	 *	\details	コンテナにインスタンスのポインタを入れたとき、一括削除するために用意
	 */
	struct Deleter
	{
		template<typename T>
		void operator() ( T* object ) const
		{
			if ( object != 0 )
			{
				delete object;
				object = 0;
			}
		}
	};

}		// namespace Mh

#endif	/* _MH_UTIL_HPP_ */