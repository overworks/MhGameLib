#ifndef _MH_SAMPLE_EMPTY_APP_HPP_
#define _MH_SAMPLE_EMPTY_APP_HPP_

#include <mh/win32/winapp.hpp>

namespace Mh
{
	class D3D11App : public WinApp
	{
	public:
		D3D11App(HINSTANCE hInstance, LPTSTR lpCmdLine, int nCmdShow);
		virtual ~D3D11App();
		
		virtual bool initialize(LPCTSTR title, uint width, uint height);
		virtual void finalize();

		virtual int run();
	};
}

#endif // _MH_SAMPLE_EMPTY_APP_HPP_