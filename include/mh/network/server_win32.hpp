#ifndef	_MH_NETWORK_SERVER_WIN32_HPP_
#define	_MH_NETWORK_SERVER_WIN32_HPP_

/*
 *	윈도우용 서버...
 */

#include "server.hpp"
#include "socket_win32.hpp"

namespace Mh
{
	namespace Network
	{
		class ServerWin32 : public Server
		{
		public:
			SERVER_INTERFACE(ServerWin32);

		};
	}	// namespace Mh::Network
}		// namespace Mh

#endif	/* _MH_NETWORK_SERVER_WIN32_HPP_ */