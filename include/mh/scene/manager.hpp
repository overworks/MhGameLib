#ifndef	_MH_SCENE_MANAGER_HPP_
#define	_MH_SCENE_MANAGER_HPP_

#include <cassert>
#include <list>
#include <algorithm>
#include <functional>
#include <mh/math.hpp>
#include "node.hpp"

/*!
 *	Mh::Scene::Manager
 *
 *	장면 관리자 클래스
 */
namespace Mh
{
	class Renderer;

	namespace Scene
	{
		class Camera;
		class Light;

		class Manager
		{
		public:		// 내부 타입 정의
			typedef std::list<Node*> NodeList;
			
		public:
						Manager();
			virtual		~Manager();

			void		set_camera( Camera* camera );
			void		render(Renderer* renderer);

			void		set_ambient_color( const ColorF& ambient );
			void		add_light( Light* light );		// 라이트 번호(핸들)을 돌려주는게 나을까...

			
		private:
			NodeList	m_node_list;
			Renderer*	m_renderer;
			Camera*		m_current_camera;

			ColorF		m_ambient_color;
		};

	}	// namespace Mh::Scene
}		// namespace Mh


#include "manager.inl"

#endif	/* _MH_SCENE_MANAGER_HPP_ */