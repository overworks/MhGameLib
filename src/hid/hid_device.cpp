#include <mh/hid/device.hpp>
#include <mh/array.hpp>
#include <mh/tuple.hpp>

namespace Mh
{
	namespace HID
	{
		Device::Device( DeviceType type )
			:	m_type( type )
		{
		}

		Device::~Device()
		{}
	}		// namespace Mh::HID
}			// namespace Mh