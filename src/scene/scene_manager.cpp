/*
 *	장면 관리자 클래스 정의
 */

#include <algorithm>
#include <functional>

#include <mh/scene/manager.hpp>

namespace Mh
{
	namespace Scene
	{
		Manager::Manager()
		{
		}

		Manager::~Manager()
		{}

		void Manager::set_ambient_color( const ColorF& ambient )
		{
			m_ambient_color = ambient;
		}

	}	// namespace Mh::Scene
}		// namespace Mh