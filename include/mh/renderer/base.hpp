#ifndef	_MH_RENDERER_BASE_H_
#define	_MH_RENDERER_BASE_H_

#include <mh/types.hpp>
#include <mh/math.hpp>

#define	RENDERER_INTERFACE(terminal)\
	virtual bool initialize() ## terminal\
	virtual void finalize() ## terminal\
	virtual bool on_resize( uint width, uint height ) ## terminal\
	virtual void set_texture( Resource::Texture* texture ) ## terminal\
	virtual bool begin_render() ## terminal\
	virtual void end_render() ## terminal\
	virtual void set_viewport( const Viewport& viewport ) ## terminal\

#define	RENDERER_BASE_INTERFACE()		RENDERER_INTERFACE(=0;)
#define	RENDERER_DERIVED_INTERFACE()	RENDERER_INTERFACE(;)

namespace Mh
{
	namespace Resource
	{
		class Texture;
	//	class Buffer;
	//	class Program;
	}

	class MH_CLASS Renderer
	{
	public:
		struct Viewport
		{
			sint	x;
			sint	y;
			sint	width;
			sint	height;
			real	near_z;
			real	far_z;
		};

	public:
		Renderer();
		virtual ~Renderer();
		RENDERER_BASE_INTERFACE();

		void			set_clear_color( const ColorF& color )	{ m_clear_color = color; }
		const ColorF&	get_clear_color() const					{ return m_clear_color; }

	private:
		ColorF			m_clear_color;
		RectI			m_scissor_rect;
	};

}		// namespace Mh

#endif	/* _MH_RENDERER_BASE_H_ */