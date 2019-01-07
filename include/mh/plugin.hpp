#ifndef _MH_PLUGIN_HPP_
#define	_MH_PLUGIN_HPP_

#include <mh/prerequisite.h>

#define	PLUGIN_INTERFACE(terminal)\
	virtual bool	install() ## terminal\
	virtual bool	initialize() ## terminal\
	virtual void	shutdown() ## terminal\
	virtual void	uninstall() ## terminal\

#define	PLUGIN_BASE_INTERFACE()		PLUGIN_INTERFACE(=0;)
#define	PLUGIN_DERIVED_INTERFACE()	PLUGIN_INTERFACE(;)

namespace Mh
{
	/**
	 *	@brief	App 클래스에 등록해서 쓰는 플러그인 인터페이스
	 */
	class MH_CLASS Plugin
	{
	public:
		Plugin();
		virtual ~Plugin();
		PLUGIN_BASE_INTERFACE();
	};
}

#endif /* _MH_PLUGIN_HPP_ */