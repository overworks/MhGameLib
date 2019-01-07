#include <algorithm>
#include <functional>
#include <mh/scene/node.hpp>

namespace Mh
{
	namespace Scene
	{
		Node::Node()
		{
		}

		Node::~Node()
		{
		}

		void Node::update()
		{
			Spatial::update();
			
			std::for_each(m_children.begin(), m_children.end(), std::mem_fun(&Spatial::update));
		}

		void Node::render(Renderer* renderer) const
		{
			Spatial::render(renderer);

			// 여기서 적절하게 처리한 후

			// 자식들도 렌더링함

			std::for_each(m_children.begin(), m_children.end(), std::bind2nd(std::mem_fun(&Spatial::render), renderer));
		}
	}
}