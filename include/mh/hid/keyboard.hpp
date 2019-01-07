#ifndef	_MH_HID_MOUSE_HPP_
#define	_MH_HID_MOUSE_HPP_

#include "device.hpp"

namespace Mh
{
	namespace HID
	{
		class Keyboard// : public Device
		{
		public:
			class Handler
			{
			public:
				Handler();
				virtual ~Handler();
			};
			
		public:
			Keyboard();
			virtual ~Keyboard();
			
		private:
			
		};
	}	// namespace Mh::HID
}		// namespace Mh

#endif	/* _MH_HID_MOUSE_HPP_ */