#include <mh/scene/spatial.hpp>

namespace Mh
{
	namespace Scene
	{
		Spatial::Spatial()
		{}

		Spatial::~Spatial()
		{}

		void Spatial::update()
		{
			// 업데이트가 필요하지 않으면 그냥 리턴
			//if( 1 )
			{
				this->m_world_scale = this->m_local_scale;
				this->m_world_rotation = this->m_local_rotation;
				this->m_world_translation = this->m_local_translation;

				if( m_parent )
				{
					this->m_world_scale *= m_parent->m_world_scale;
					this->m_world_rotation *= m_parent->m_world_rotation;
					this->m_world_translation *= m_parent->m_world_translation;
				}

				this->m_cached_matrix = Matrix::IDENTITY;
				this->m_cached_matrix.set_scale( m_world_scale );
				this->m_cached_matrix.rotate( m_world_rotation );
			}
		}
	}
}		// namespace Mh