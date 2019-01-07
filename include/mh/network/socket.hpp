#ifndef	_MH_NETWORK_SOCKET_HPP_
#define	_MH_NETWORK_SOCKET_HPP_

#include <mh/types.hpp>
#include "types.hpp"

/*
 *	소켓 인터페이스
 *
 *	BSD 소켓과 윈속을 잘 참조해서 구현해보자...
 */

#define	SOCKET_INTERFACE(ClassName)\
	ClassName();\
	virtual ~ClassName();\
	virtual int create( int af, int type, int protocol );\
	virtual bool bind( const SockAddr* addr, size_t addr_size );\
	virtual bool connect( const SockAddr* addr, size_t* addr_size )

namespace Mh
{
	namespace Network
	{
		struct SockAddrIn
		{
			ushort		sa_family;
			char		sa_data[14];
		};

		struct SockAddr
		{
			short		sin_family;
			ushort		sin_port;
			SockAddrIn	sin_addr;
			char		sin_zero[8];
		};

		class Socket
		{
		public:
			enum Type
			{
				TYPE_STREAM		= 1,	// SOCK_STREAM
				TYPE_DGRAM		= 2,	// SOCK_DGRAM
				TYPE_RAW		= 3,	// SOCK_RAW
				TYPE_RDM		= 4,	// SOCK_RDM
				TYPE_SEQPACKET	= 5,	// SOCK_SEQPACKET
			};

		public:
			Socket()			{}
			virtual ~Socket()	{}

			/*!
			 *	소켓 생성
			 *
			 *	\param	af		주소 패밀리
			 */
			virtual int create( int af, int type, int protocol ) = 0;

			virtual bool bind( const SockAddr* addr, size_t addr_size ) = 0;
			virtual bool connect( const SockAddr* addr, size_t* addr_size ) = 0;
		};

	}	// namespace Mh::Network
}		// namespace Mh

#endif	/* _MH_NETWORK_SOCKET_HPP_ */