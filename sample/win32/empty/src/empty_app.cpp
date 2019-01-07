#include <empty_app.hpp>
#include <mh/renderer.hpp>

namespace Mh
{
	EmptyApp::EmptyApp(HINSTANCE hInstance)
		: WinApp(hInstance)
	{
	}

	EmptyApp::~EmptyApp()
	{
	}

	void EmptyApp::game_loop()
	{
		Renderer* renderer = get_renderer();
		if (renderer != nullptr && renderer->begin_render())
		{
			renderer->end_render();
		}
	}
}