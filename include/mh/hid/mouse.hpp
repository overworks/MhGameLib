#ifndef	_MH_HID_MOUSE_HPP_
#define	_MH_HID_MOUSE_HPP_

#include <vector>
#include <mh/types.hpp>
#include "device.hpp"

namespace Mh
{
	namespace HID
	{
		// 각 HID의 인터페이스 클래스
		// 이걸 상속해서 각 API(XInput이나 DirectInput등)에 맞게 구현
		class Mouse// : public Device
		{
		public:
			enum Button
			{
				BUTTON_LEFT,
				BUTTON_RIGHT,
				BUTTON_CENTER,
			};
			
			class Listener
			{
			public:
				Listener();
				virtual ~Listener();
				
				virtual bool on_move( uint x, uint y ) = 0;
				virtual bool on_button_up( Button button ) = 0;
				virtual bool on_button_down( Button button ) = 0;
				virtual bool on_click( Button button ) = 0;
				virtual bool on_double_click( Button button ) = 0;
			};
			
			// 벡터가 아니라 셋으로 해야할지도...
			typedef	std::vector<Listener*>		ListenerVec;
			typedef	ListenerVec::iterator		ListenerIter;
			typedef	ListenerVec::const_iterator	ListenerConstIter;

		public:
			Mouse()		{}
			virtual ~Mouse() {}
			
			void	add_listener( Listener* listener );
			
			void	on_update( int button, int state, int x, int y );
			
		private:			
			ListenerVec	m_listeners;
		};
	}	// namespace Mh::HID
}		// namespace Mh

#endif	/* _MH_HID_MOUSE_HPP_ */