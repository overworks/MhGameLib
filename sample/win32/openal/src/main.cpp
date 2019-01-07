#include <openal_app.hpp>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpCmdLine, int nCmdShow)
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	Mh::OpenALApp app(hInstance, lpCmdLine, nCmdShow);
	
	int result = 0;
	if (app.initialize(_T("Test"), 640, 480))
	{
		result = app.run();
		app.finalize();
	}

	return result;
}