#include <mh/hid/xinput.hpp>

/*
 *	XInput 클래스 정의
 */
namespace Mh
{
	namespace HID
	{
		typedef	::DWORD	(WINAPI *UpdateFuncPtr)( ::DWORD, ::XINPUT_STATE* );

		static ::HMODULE		s_module = NULL;
		static UpdateFuncPtr	s_update_func;

		/*
		 *	이하 GamepadXI 구현
		 */
		GamepadXI::GamepadXI( uint index )
			:	Gamepad( index )
		{}

		GamepadXI::~GamepadXI()
		{}

		bool GamepadXI::initialize()
		{
			bool result = false;

			// 접속되어있는 컨트롤러의 기능 점검
			

			return result;
		}

		void GamepadXI::finalize()
		{
			ZeroMemory( &m_state, sizeof(::XINPUT_STATE) );
		}

		void GamepadXI::update()
		{
			if( is_connected() )
			{
				const ::DWORD result = (*s_update_func)( get_index(), &m_state );
				if( ERROR_DEVICE_NOT_CONNECTED == result )
				{
					// 여기서 접속이 끊어졌다는 메시지를 내야할듯...
					m_connected = false;
				}
			}
		}
		
		/*
		 *	이하 ManagerXI 구현
		 */
		ManagerXI::ManagerXI()
		{}

		ManagerXI::~ManagerXI()
		{}

		bool ManagerXI::initialize( Mh::uint devices )
		{
			bool result = false;

			// 라이브러리 링크
			s_module = ::LoadLibrary( XINPUT_DLL );
			if( s_module )
			{
				s_update_func = (UpdateFuncPtr)::GetProcAddress( s_module, "XInputGetState" );
			}

			// 현재 게임패드 초기화
			for( uint i = 0; i < 4; ++i )
			{
				m_gamepad[i] = new GamepadXI(i);
			}

			devices;
			return result;
		}

		void ManagerXI::update()
		{
		}

		void ManagerXI::finalize()
		{
			for( ::DWORD i = 0; i < 4; ++i )
			{
				SafeDelete( &m_gamepad[i] );
			}

			if( s_update_func )
				s_update_func = NULL;

			// 라이브러리 제거
			if( s_module )
			{
				::FreeLibrary( s_module );
				s_module = NULL;
			}
		}

	}	// namespace Mh::HID
}		// namespace Mh