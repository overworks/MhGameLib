#include <mh/xaudio2/source.hpp>

namespace Mh
{
	namespace Audio
	{
		SourceXA2::SourceXA2(::IXAudio2* xa2, const ::WAVEFORMATEX* format)
			: m_source(nullptr)
		{
			xa2->CreateSourceVoice(&m_source, format);
		}

		SourceXA2::~SourceXA2()
		{
			
		}
	}
}