#ifndef _MH_XAUDIO2_SOURCE_HPP_
#define	_MH_XAUDIO2_SOURCE_HPP_

#include <xaudio2.h>
#include <mh/audio.hpp>

namespace Mh
{
	namespace Audio
	{
		class MH_CLASS SourceXA2 : public Source
		{
		public:
			SourceXA2(::IXAudio2* xa2, const ::WAVEFORMATEX* format);
			virtual ~SourceXA2();
			AUDIO_SOURCE_DERIVED_INTERFACE();

		private:
			::IXAudio2SourceVoice*	m_source;
		};
	}
}

#endif /* _MH_XAUDIO2_SOURCE_HPP_ */