#ifndef	_MH_APP_HPP_
#define	_MH_APP_HPP_

#include <vector>
#include <mh/prerequisite.h>
#include <mh/types.hpp>
#include <mh/util.hpp>

namespace Mh
{
	class Renderer;
	
	// 애플리케이션 인터페이스
	class MH_CLASS App : public Singleton<App>
	{
	public:
		App();
		virtual ~App();
		virtual void	game_loop() = 0;

		void			set_renderer( Renderer* renderer )	{ m_current_renderer = renderer; }

		const Renderer*	get_renderer() const				{ return m_current_renderer; }
		Renderer*		get_renderer()						{ return m_current_renderer; }

		void set_client_width( uint width )					{ m_client_width = width; }
		void set_client_height( uint height )				{ m_client_height = height; }
		uint get_client_width() const						{ return m_client_width; }
		uint get_client_height() const						{ return m_client_height; }

	private:
		uint			m_client_width;
		uint			m_client_height;

		Renderer*		m_current_renderer;
	};
}

#endif	/* _MH_APP_HPP_ */