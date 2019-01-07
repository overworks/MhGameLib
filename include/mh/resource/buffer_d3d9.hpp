#ifndef	_MH_RESOURCE_BUFFER_D3D9_HPP_
#define	_MH_RESOURCE_BUFFER_D3D9_HPP_

/*!
 *	Direct3D9용 버퍼 리소스
 */

#include <d3d9.h>
#include "buffer.hpp"

namespace Mh
{
	namespace Resource
	{
		class VertexBufferD3D9 : public VertexBuffer
		{
		public:
			VertexBufferD3D9();
			virtual ~VertexBufferD3D9();

		private:
			IDirect3DVertexBuffer9*		m_buffer;
		};

		class IndexBufferD3D9 : public IndexBuffer
		{
		public:
			IndexBufferD3D9();
			virtual ~IndexBufferD3D9();

		private:
			IDirect3DIndexBuffer9*		m_buffer;
		};
	}
};

#endif	/* _MH_RESOURCE_BUFFER_D3D9_HPP_ */