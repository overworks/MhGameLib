#ifndef _MH_OPENAL_SOURCE_HPP_
#define	_MH_OPENAL_SOURCE_HPP_

#include <al.h>
#include <mh/audio.hpp>

namespace Mh
{
	namespace Audio
	{
		class SourceOpenAL : public Source
		{
		public:
			SourceOpenAL();
			virtual ~SourceOpenAL();
			AUDIO_SOURCE_DERIVED_INTERFACE();

			void attach_buffer(Buffer* buffer);

			::ALint get_raw_id() const { return m_id; }

		private:
			::ALuint	m_id;
		};
	}
}

#endif	/* _MH_OPENAL_SOURCE_HPP_ */