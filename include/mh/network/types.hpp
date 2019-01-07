#ifndef	_MH_NETWORK_TYPES_HPP_
#define	_MH_NETWORK_TYPES_HPP_

/*
 *	네트워크용 타입
 *
 *	IP, TCP, UDP 뭐 그런거...
 *	나중에 적절하게 윈속이랑 BSD 소켓을 확인해서 중첩
 */

namespace Mh
{
	namespace Network
	{
#if 0		// 참고로만 해두자. BSD와 윈속에서 공통인 것들

		// Address Families
		enum
		{
			AF_UNSPEC		= 0,
			AF_UNIX			= 1,
			AF_LOCAL		= 1,
			AF_INET			= 2,
			AF_IMPLINK		= 3,
			AF_PUP			= 4,
			AF_CHAOS		= 5,
			AF_IPX			= 6,
			AF_NS			= 6,
			AF_ISO			= 7,
			AF_OSI			= AF_ISO,
			AF_ECMA			= 8,
			AF_DATAKIT		= 9,
			AF_CCITT		= 10,
			AF_SNA			= 11,
			AF_DECnet		= 12,
			AF_DLI			= 13,
			AF_LAT			= 14,
			AF_HYLINK		= 15,
			AF_APPLETALK	= 16,
			AF_NETBIOS		= 17,
			AF_VOICEVIEW	= 18,
			AF_FIREFOX		= 19,
			AF_UNKNOWN1		= 20,
			AF_BAN			= 21,

			AF_INET6		= 23,
			AF_IRDA			= 26,
			AF_BTH			= 32,

			AF_MAX,
		};

		// Socket Types
		enum
		{
			SOCK_STREAM		= 1,
			SOCK_DGRAM		= 2,
			SOCK_RAW		= 3,
			SOCK_RDM		= 4,
			SOCK_SEQPACKET	= 5,
		};

		// Protocols
		enum
		{
			IPPROTO_IP		= 0,
			IPPROTO_ICMP	= 1,
			IPPROTO_IGMP	= 2,
			IPPROTO_GGP		= 3,
			IPPROTO_TCP		= 6,
			IPPROTO_PUP		= 12,
			IPPROTO_UDP		= 17,
			IPPROTO_IDP		= 22,
			IPPROTO_ICMPV6	= 58,
			IPPROTO_ND		= 77,
			IPPROTO_RM		= 123,
			IPPROTO_RAW		= 255,

			IPPROTO_MAX		= 256,
		};
#endif

	}	// namespace Mh::Network
}		// namespace Mh

#endif	/* _MH_NETWORK_CLIENT_HPP_ */