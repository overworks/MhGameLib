#ifndef _MH_AUDIO_XAUDIO2_SYSTEM_HPP_
#define	_MH_AUDIO_XAUDIO2_SYSTEM_HPP_

#include <xaudio2.h>
#include <mh/audio.hpp>

namespace Mh
{
	namespace Audio
	{
		class MH_CLASS SystemXA2 : public System
		{
		public:
			SystemXA2();
			virtual ~SystemXA2();
			AUDIO_SYSTEM_DERIVED_INTERFACE();

		public:
			::IXAudio2* m_xa2;
			::IXAudio2MasteringVoice* m_master_voice;
		};
	}
}


#endif	/* _MH_AUDIO_XAUDIO2_SYSTEM_HPP_ */