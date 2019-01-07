#include <empty_app.hpp>

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR, int nCmdShow)
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	Mh::EmptyApp app(hInstance);
	
	int result = 0;
	if (app.initialize(640, 480, L"Empty"))
	{
		result = app.run(nCmdShow);
	}

	return result;
}