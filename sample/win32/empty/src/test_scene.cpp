#include <mh/util.hpp>
#include <mh/renderer.hpp>
#include <test_scene.hpp>

namespace Mh
{
	struct TestVertex
	{
		float x, y, z;

	};

	TestScene::TestScene()
		: m_manager(nullptr)
	{
	}

	TestScene::~TestScene()
	{
		SafeDelete(&m_manager);
	}

	void TestScene::update()
	{

	}

	void TestScene::render(Renderer* renderer)
	{
		renderer->begin_render();

		renderer->end_render();
	}

}