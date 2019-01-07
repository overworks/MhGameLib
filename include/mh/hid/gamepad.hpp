#ifndef	_MH_HID_GAMEPAD_HPP_
#define	_MH_HID_GAMEPAD_HPP_

#include <mh/types.hpp>
#include "device.hpp"

#define	HID_GAMEPAD_INTERFACE(terminal)\
	virtual bool initialize()##terminal\
	virtual void finalize()##terminal\
	virtual void update()##terminal\

#define	HID_GAMEPAD_BASE_INTERFACE()	HID_GAMEPAD_INTERFACE(=0;)
#define	HID_GAMEPAD_DERIVED_INTERFACE()	HID_GAMEPAD_INTERFACE(;)

namespace Mh
{
	namespace HID
	{
		enum GamepadButton
		{
		};
		
		class GamepadHandler
		{
		public:
			bool on_button_pushed();
		};

		class Gamepad// : public DeviceBase
		{
		public:
			Gamepad( uint index );
			virtual ~Gamepad();
			HID_GAMEPAD_BASE_INTERFACE();

			uint	get_index() const		{ return m_index; }

		private:
			Gamepad& operator = ( const Gamepad& );	// for C4512
			
			const uint	m_index;
		};

		/*
		 *	게임패드 관리자 클래스
		 */
		class GamepadManager
		{
		public:
			enum { MAX_GAMEPAD = 4 };


		private:
			Gamepad*	m_gamepad[MAX_GAMEPAD];		// 최대 4개

		};

	}	// namespace Mh::HID
}		// namespace Mh

#endif	/* _MH_HID_GAMEPAD_HPP_ */