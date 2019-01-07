#include <mh/openal/source.hpp>

#ifdef _MH_DEBUG_
#define	CHECK_AL_ERROR()\
	{\
		ALenum alError = ::alGetError();\
		if (alError != AL_NO_ERROR)\
		{\
		}\
	}
#else
#define	CHECK_AL_ERROR()
#endif // _MH_DEBUG_

namespace Mh
{
	namespace Audio
	{
		SourceOpenAL::SourceOpenAL()
			: m_id(0)
		{
			::alGenSources(1, &m_id);
			CHECK_AL_ERROR();
		}

		SourceOpenAL::~SourceOpenAL()
		{
			if (m_id)
			{
				::alDeleteSources(1, &m_id);
				m_id = 0;
			}
		}

		void SourceOpenAL::play()
		{
			::alSourcePlay(m_id);
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::stop()
		{
			::alSourceStop(m_id);
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::rewind()
		{
			::alSourceRewind(m_id);
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::pause()
		{
			::alSourcePause(m_id);
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::set_position(const Float3& position)
		{
			::alSourcefv(m_id, AL_POSITION, reinterpret_cast<const ALfloat*>(&position));
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::set_direction(const Vector3& direction)
		{
			::alSourcefv(m_id, AL_DIRECTION, reinterpret_cast<const ALfloat*>(&direction));
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::set_velocity(const Vector3& velocity)
		{
			::alSourcefv(m_id, AL_VELOCITY, reinterpret_cast<const ALfloat*>(&velocity));
			CHECK_AL_ERROR();
		}

		Float3 SourceOpenAL::get_position() const
		{
			Float3 position;
			::alGetSourcefv(m_id, AL_POSITION, reinterpret_cast<ALfloat*>(&position));
			CHECK_AL_ERROR();
			return position;
		}

		Vector3 SourceOpenAL::get_direction() const
		{
			Vector3 direction;
			::alGetSourcefv(m_id, AL_DIRECTION, reinterpret_cast<ALfloat*>(&direction));
			CHECK_AL_ERROR();
			return direction;
		}

		Vector3	SourceOpenAL::get_velocity() const
		{
			Vector3 velocity;
			::alGetSourcefv(m_id, AL_VELOCITY, reinterpret_cast<ALfloat*>(&velocity));
			CHECK_AL_ERROR();
			return velocity;
		}

		void SourceOpenAL::get_position(Float3* position) const
		{
			::alGetSourcefv(m_id, AL_POSITION, reinterpret_cast<ALfloat*>(position));
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::get_direction(Vector3* direction) const
		{
			::alGetSourcefv(m_id, AL_DIRECTION, reinterpret_cast<ALfloat*>(direction));
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::get_velocity(Vector3* velocity) const
		{
			::alGetSourcefv(m_id, AL_VELOCITY, reinterpret_cast<ALfloat*>(velocity));
			CHECK_AL_ERROR();
		}

		void SourceOpenAL::attach_buffer(Buffer* buffer)
		{

		}
	}
}