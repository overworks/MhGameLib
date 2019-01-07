#include <mh/openal.hpp>
#include <openal_app.hpp>

namespace Mh
{
	OpenALApp::OpenALApp(HINSTANCE hInstance, LPTSTR lpCmdLine, int nCmdShow)
		: WinApp(hInstance, lpCmdLine, nCmdShow), m_audio_system(nullptr)
	{
	}

	OpenALApp::~OpenALApp()
	{
	}

	bool OpenALApp::initialize( LPCTSTR title, uint width, uint height )
	{
		bool success = WinApp::initialize(title, width, height);

		if (success)
		{
			m_audio_system = new Audio::SystemOpenAL();
			success = m_audio_system->initialize();
		}

		return success;
	}

	void OpenALApp::finalize()
	{
		WinApp::finalize();

		if (m_audio_system != nullptr)
		{
			m_audio_system->finalize();
			delete m_audio_system;
			m_audio_system = nullptr;
		}
	}
}