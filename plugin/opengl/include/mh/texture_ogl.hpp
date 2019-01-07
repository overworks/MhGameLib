#ifndef _MH_TEXTURE_OGL_HPP_
#define _MH_TEXTURE_OGL_HPP_

#include <gl/GL.h>
#include <mh/resource.hpp>

namespace Mh
{
	class RendererOGL;

	namespace Resource
	{
		class TextureOGL : public Texture
		{
			friend class RendererOGL;

		public:
			TextureOGL();
			virtual ~TextureOGL();

			RESOURCE_TEXTURE_DERIVED_INTERFACE();

		private:
			GLuint m_texture_id;
		};
	}
}

#endif // _MH_TEXTURE_OGL_HPP_