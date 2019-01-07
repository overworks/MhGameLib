#include <mh/openal/system.hpp>
#include <mh/openal/buffer.hpp>

namespace Mh
{
	namespace Audio
	{
		SystemOpenAL::SystemOpenAL()
			: m_device(nullptr), m_context(nullptr)
		{}

		SystemOpenAL::~SystemOpenAL()
		{}

		bool SystemOpenAL::initialize()
		{
			bool result = false;

			m_device = alcOpenDevice(nullptr);
			if (m_device)
			{
				m_context = alcCreateContext(m_device, nullptr);
				alcMakeContextCurrent(m_context);

				result = true;
			}

			return result;
		}

		void SystemOpenAL::finalize()
		{
			if (m_context != nullptr)
			{
				alcDestroyContext(m_context);
				m_context = nullptr;
			}

			if (m_device != nullptr)
			{
				alcCloseDevice(m_device);
				m_device = nullptr;
			}
		}

		void SystemOpenAL::suspend()
		{
			alcSuspendContext(m_context);
		}

		void SystemOpenAL::process()
		{
			alcProcessContext(m_context);
		}
	}
}