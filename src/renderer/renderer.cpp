#include <mh/renderer.hpp>

namespace Mh
{
	Renderer::Renderer()
		: m_clear_color(0xffffffff)
	{}

	Renderer::~Renderer()
	{}

	bool Renderer::initialize()
	{
		return false;
	}

	void Renderer::finalize()
	{}

	bool Renderer::on_resize(uint width, uint height)
	{
		return false;
	}

	bool Renderer::begin_render()
	{
		return false;
	}

	void Renderer::end_render()
	{}

	void Renderer::set_viewport(const Viewport& viewport)
	{
	}
}