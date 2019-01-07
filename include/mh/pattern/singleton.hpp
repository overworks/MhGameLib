#ifndef	_MH_PATTERN_SINGLETON_
#define	_MH_PATTERN_SINGLETON_

#include	<cassert>

namespace	Mh
{
	/*!
	 *	\brief	단일체 클래스(from GPG)
	 */
	template <typename T>
	class Singleton
	{
	private:
		Singleton( const Singleton& );
		const Singleton& operator = ( const Singleton& );

	protected:
		Singleton()					{ assert( !ms_pInstance );	ms_pInstance = static_cast<T*>(this); }
		~Singleton()				{ assert( ms_pInstance );	ms_pInstance = 0; }

	public:
		static T& get_instance()		{ assert( ms_pInstance );	return *ms_pInstance; }
		static T* get_instance_ptr()	{ return ms_pInstance; }

	private:
		static T*	ms_pInstance;
	};

	template <typename T>
	T* Singleton<T>::ms_pInstance = 0;

}		// namespace Mh

#endif	/* _MH_PATTERN_SINGLETON_ */