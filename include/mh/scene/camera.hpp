#ifndef	_MH_SCENE_CAMERA_HPP_
#define	_MH_SCENE_CAMERA_HPP_

#include <mh/math.hpp>

namespace Mh
{
	namespace Scene
	{
		class Camera
		{
		public:
			Camera();
			virtual ~Camera();

			virtual void update();
			
			void	set_view_matrix( const Vector3& position, const Vector3& target, const Vector3& up );
			void	set_projection_matrix();

		private:
			//bool	m_modified;

			Vector3	m_position;
			Vector3	m_target;
			Vector3	m_up;

			Matrix	m_view_matrix;
			Matrix	m_projection_matrix;

		};
		
	}	// namespace Mh::Scene
}		// namespace Mh

#endif	/* _MH_SCENE_CAMERA_HPP_ */