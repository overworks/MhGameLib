#ifndef _MH_AUDIO_OPENAL_BUFFER_HPP_
#define	_MH_AUDIO_OPENAL_BUFFER_HPP_

#include <al.h>
#include <mh/audio.hpp>

namespace Mh
{
	namespace Audio
	{
		class MH_CLASS BufferOpenAL : public Buffer
		{
		public:
			BufferOpenAL();
			virtual ~BufferOpenAL();
			AUDIO_BUFFER_DERIVED_INTERFACE();

		private:
			::ALuint	m_buffer;
		};
	}
}

#endif	/* _MH_AUDIO_OPENAL_BUFFER_HPP_ */