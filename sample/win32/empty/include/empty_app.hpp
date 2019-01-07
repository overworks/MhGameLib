#ifndef _MH_SAMPLE_EMPTY_APP_HPP_
#define _MH_SAMPLE_EMPTY_APP_HPP_

#include <mh/winapp.hpp>

namespace Mh
{
	class EmptyApp : public WinApp
	{
	public:
		EmptyApp(HINSTANCE hInstance);
		virtual ~EmptyApp();
		virtual void game_loop();
	};
}

#endif // _MH_SAMPLE_EMPTY_APP_HPP_