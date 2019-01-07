#ifndef	_MH_SCENE_NODE_HPP_
#define	_MH_SCENE_NODE_HPP_

#include <list>
#include "spatial.hpp"

namespace Mh
{
	namespace Scene
	{
		class Node : public Spatial
		{
		public:
			Node();
			virtual ~Node();
			virtual void update();
			virtual void render(Renderer* renderer) const;

		private:
		//	std::vector<Spatial*>	m_children;
			std::list<Spatial*>	m_children;
		};

	}	// namespace Mh::Scene
}		// namespace Mh

#endif	/* _MH_SCENE_NODE_HPP_ */