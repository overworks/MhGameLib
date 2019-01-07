#ifndef _MH_SAMPLE_OPENAL_APP_HPP_
#define	_MH_SAMPLE_OPENAL_APP_HPP_

#include <mh/win32/winapp.hpp>

namespace Mh
{
	class OpenALApp : public WinApp
	{
	public:
		OpenALApp(HINSTANCE hInst, LPTSTR lpCmdLine, int nCmdShow);
		virtual ~OpenALApp();

		virtual bool	initialize( LPCTSTR title, uint width, uint height );
		virtual void	finalize();

	private:
		Audio::System*	m_audio_system;
	};
}

#endif	/* _MH_SAMPLE_OPENAL_APP_HPP_ */