#ifndef _MH_XAUDIO2_LISTENER_HPP_
#define	_MH_XAUDIO2_LISTENER_HPP_

#include <xaudio2.h>
#include <mh/audio.hpp>

namespace Mh
{
	namespace Audio
	{
		class ListenerXA2 : public Listener
		{
		public:
			ListenerXA2();
			virtual ~ListenerXA2();
			AUDIO_LISTENER_DERIVED_INTERFACE();

		private:

		};
	}
}

#endif /* _MH_XAUDIO2_LISTENER_HPP_ */