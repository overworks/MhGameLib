#include <mh/renderer_ogl.hpp>
#include <mh/texture_ogl.hpp>

namespace Mh
{
	RendererOGL::RendererOGL()
	{}

	RendererOGL::~RendererOGL()
	{}

	bool RendererOGL::initialize(const Renderer::Desc& desc)
	{
		return true;
	}

	void RendererOGL::finalize()
	{

	}

	bool RendererOGL::begin_render()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		return true;
	}

	void RendererOGL::end_render()
	{
		glFlush();
	}

	bool RendererOGL::on_resize(uint width, uint height)
	{
		return true;
	}

	void RendererOGL::set_viewport(const Renderer::Viewport& viewport)
	{
		glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
		glDepthRange(viewport.near_z, viewport.far_z);
	}

	void RendererOGL::set_clear_color(const ColorF& color)
	{
		Renderer::set_clear_color(color);
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void RendererOGL::set_texture(Resource::Texture* texture)
	{
		Resource::TextureOGL* tex = static_cast<Resource::TextureOGL*>(texture);
		glBindTexture(GL_TEXTURE_2D, tex->m_texture_id);
	}
}