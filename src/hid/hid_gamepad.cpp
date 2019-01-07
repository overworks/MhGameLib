#include <mh/hid/gamepad.hpp>

namespace Mh
{
	namespace HID
	{
		/*
		 *	게임패드 구현
		 */
		Gamepad::Gamepad( uint index )
			:	m_index( index )
		{}

		Gamepad::~Gamepad()
		{}

		/*
		 *	게임패드 관리자 구현
		 */

	}	// namespace Mh::HID
}		// namespace Mh