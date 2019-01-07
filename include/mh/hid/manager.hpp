#ifndef	_MH_HID_MANAGER_HPP_
#define	_MH_HID_MANAGER_HPP_

#include <mh/types.hpp>
#include <mh/util.hpp>
#include "device.hpp"

#define	HID_MANAGER_INTERFACE(terminal)\
	virtual bool initialize( uint devices )##terminal\
	virtual void finalize()##terminal\
	virtual void update()##terminal\

#define	HID_MANAGER_BASE_INTERFACE()	HID_MANAGER_INTERFACE(=0;)
#define	HID_MANAGER_DERIVED_INTERFACE()	HID_MANAGER_INTERFACE(;)


namespace Mh
{
	namespace HID
	{
		class Mouse;
		class Keyboard;
		class Gamepad;

		// 매니저 클래스의 문제는... 어떻게 메시지 프로시저 함수에서 값을 가져올 것인가 하는 것임.
		// 그냥 대놓고 friend 선언하는 방법도 있긴 한데 그럼 유연성은 안드로메다...
		// 일단 파생 클래스를 만들어서 거기서 처리를 해봐야겠다... 되긴 할지 모르겠지만;
		
		// 플랫폼에 맞춰서 핸들러를 구현해두고, 장치 클래스에서 핸들러 입력을 받도록 해야겠다...
		
		class Manager : public Singleton<Manager>
		{
		public:
			Manager();
			virtual ~Manager();

			HID_MANAGER_BASE_INTERFACE();
			
			bool enable( DeviceType type );
			bool disable( DeviceType type );
			bool is_enabled( DeviceType type ) const;
			
			Mouse*			get_mouse()							{ return m_mouse; }
			const Mouse*	get_mouse() const					{ return m_mouse; }
			Keyboard*		get_keyboard()						{ return m_keyboard; }
			const Keyboard*	get_keyboard() const				{ return m_keyboard; }
			Gamepad*		get_gamepad( size_t index )			{ return m_gamepad[index]; }
			const Gamepad*	get_gamepad( size_t index ) const	{ return m_gamepad[index]; }
			
		protected:
			Mouse*		m_mouse;
			Keyboard*	m_keyboard;
			Gamepad*	m_gamepad[4];
		};
		
	}	// namespace Mh::HID
}		// namespace Mh

#endif	/* _MH_HID_MANAGER_HPP_ */