#ifndef	_MH_RESOURCE_BUFFER_
#define	_MH_RESOURCE_BUFFER_

#include "base.hpp"

namespace Mh
{
	namespace Resource
	{
		// 버퍼 클래스
		// 렌더러 별로 상속해서 구현함
		class Buffer
		{
		public:
			Buffer();
			virtual ~Buffer();
		};

		class VertexBuffer : public Buffer
		{
		public:
			VertexBuffer();
			virtual ~VertexBuffer();
		};

		class IndexBuffer : public Buffer
		{
		public:
			IndexBuffer();
			virtual ~IndexBuffer();
		};

		// 상수 버퍼... 이건 좀 더 생각해보고...
		class ConstantBuffer : public Buffer
		{
		public:
			ConstantBuffer();
			virtual ~ConstantBuffer();
		};

		
	}	// namespace Mh::Resource
}		// namespace Mh

#endif	/* _MH_RESOURCE_BUFFER_ */