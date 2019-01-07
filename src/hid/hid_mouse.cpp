#include <mh/hid/mouse.hpp>

namespace Mh
{
	namespace HID
	{		
		
		void Mouse::add_listener( Mouse::Listener* listener )
		{
			m_listeners.push_back( listener );
		}
		
	}	// namespace HID
}		// namespace Mh