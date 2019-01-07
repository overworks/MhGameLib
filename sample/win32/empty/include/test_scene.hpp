#ifndef _MH_TEST_SCENE_HPP_
#define _MH_TEST_SCENE_HPP_

#include <mh/scene.hpp>

namespace Mh
{
	// 전방선언
	class Renderer;
	
	class TestScene
	{
	public:
		TestScene();
		~TestScene();

		void update();
		void render(Renderer* renderer);

	private:
		Scene::Manager* m_manager;
	};
}

#endif // _MH_TEST_SCENE_HPP_