#ifndef	_MH_NETWORK_SOCKET_WIN32_HPP_
#define	_MH_NETWORK_SOCKET_WIN32_HPP_

/*!
 *	윈도우용 소켓(WinSock)
 */

#include <winsock.h>
#include "socket.hpp"

namespace Mh
{
	namespace Network
	{
		class SocketWin32 : public Socket
		{
		public:
			SOCKET_INTERFACE(SocketWin32);

		private:
			SOCKET	m_handle;

			// static members
		public:
			/*!
			 *	소켓 초기화
			 *
			 *	\ref	WSAStartup()
			 *	\param	version		소켓 버전. MAKEWORD 매크로를 사용할것
			 *	\return	성공하면 0을 리턴
			 */
			static int startup( WORD version );
			static int cleanup();

		private:		// 차후 그냥 소스 안에서 때려버릴수도...(결국 static인데 private으로 할 필요가 있나?)
			static ::HMODULE	s_module;
			static ::WSADATA	s_wsa_data;

		};
	}	// namespace Mh::Network
}		// namespace Mh


#endif	/* _MH_NETWORK_SOCKET_WIN32_HPP_ */