#ifndef	_MH_NETWORK_SERVER_HPP_
#define	_MH_NETWORK_SERVER_HPP_

/*
 *	서버 인터페이스
 */

#include <mh/types.hpp>

#define		SERVER_INTERFACE(name)\
	name();\
	virtual ~name();\
	virtual bool initialize( u32 address, u16 port );\
	

namespace Mh
{
	namespace Network
	{
		class Socket;

		// 전송 프로토콜
		enum TP		// Transfort protocol
		{
			TP_TCP,			// 일단은 이 두개만...
			TP_UDP,
		};

		struct ServerDesc
		{
			u32 addrees;		// 서버 주소
			u16	port;			// 포트
			TP	protocol;		// 전송 프로토콜(TCP, UDP)
		};

		class Server
		{
		public:
			Server() {}
			virtual ~Server() {}
			
			virtual bool initialize( u32 address, u16 port ) = 0;
		};

	}	// namespace Mh::Network
}		// namespace Mh

#endif	/* _MH_NETWORK_SERVER_HPP_ */