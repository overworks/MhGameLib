#include <mh/openal/buffer.hpp>

namespace Mh
{
	namespace Audio
	{
		BufferOpenAL::BufferOpenAL()
			: m_buffer(0)
		{
			::alGenBuffers(1, &m_buffer);
			
			ALenum error = alGetError();
			if (error != AL_NO_ERROR)
			{
				// 뭔가 에러를 발생시켜야 함...
			}
		}

		BufferOpenAL::~BufferOpenAL()
		{
			::alDeleteBuffers(1, &m_buffer);
		}

		void BufferOpenAL::close()
		{
		}
	}
}