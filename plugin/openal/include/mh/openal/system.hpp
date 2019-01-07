#ifndef _MH_AUDIO_OPENAL_SYSTEM_HPP_
#define	_MH_AUDIO_OPENAL_SYSTEM_HPP_

#include <al.h>
#include <alc.h>
#include <mh/audio.hpp>

namespace Mh
{
	namespace Audio
	{
		class MH_CLASS SystemOpenAL : public System
		{
		public:
			SystemOpenAL();
			virtual ~SystemOpenAL();
			AUDIO_SYSTEM_DERIVED_INTERFACE();

		private:
			::ALCdevice*	m_device;
			::ALCcontext*	m_context;
		};
	}
}

#endif	/* _MH_AUDIO_OPENAL_SYSTEM_HPP_ */