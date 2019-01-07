#ifndef _MH_RENDERER_OPENGL_HPP_
#define _MH_RENDERER_OPENGL_HPP_

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32
#include <gl/GL.h>
#include <mh/renderer.hpp>

namespace Mh
{
	namespace Resource
	{
		class Texture;
	}

	class MH_CLASS RendererOGL : public Renderer
	{
	public:
		RendererOGL();
		virtual ~RendererOGL();
		RENDERER_DERIVED_INTERFACE();

		virtual void set_clear_color(const ColorF& color);

		
		void set_texture(Resource::Texture* texture);

	private:

	};
}

#endif // _MH_RENDERER_OPENGL_HPP_