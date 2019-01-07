#ifndef	_MH_SCENE_SPATIAL_HPP_
#define	_MH_SCENE_SPATIAL_HPP_

#include <mh/prerequisite.h>
#include <mh/math.hpp>

namespace Mh
{
	class Renderer;

	namespace Scene
	{
		class Spatial
		{
		public:
			Spatial();
			virtual ~Spatial() = 0;

			virtual void update() = 0;
			virtual void render(Renderer* renderer) const = 0;

		private:
			Spatial*	m_parent;

			Vector3		m_local_scale;
			Quaternion	m_local_rotation;
			Vector3		m_local_translation;

			Vector3		m_world_scale;
			Quaternion	m_world_rotation;
			Vector3		m_world_translation;

			Matrix4x4	m_cached_matrix;
		};

	}	// namespace Mh::Scene
}		// namespace Mh


#endif	/* _MH_SCENE_SPATIAL_HPP_ */
