#include <mh/xaudio2/system.hpp>

namespace Mh
{
	namespace Audio
	{
		SystemXA2::SystemXA2()
			: m_xa2(nullptr), m_master_voice(nullptr)
		{}

		SystemXA2::~SystemXA2()
		{}

		bool SystemXA2::initialize()
		{
			HRESULT hr = ::XAudio2Create(&m_xa2, 0, XAUDIO2_DEFAULT_PROCESSOR);
			if (FAILED(hr))
				return false;
			
#ifdef _MH_DEBUG_
			::XAUDIO2_DEBUG_CONFIGURATION debug_config = { 0, };
			debug_config.TraceMask = XAUDIO2_LOG_ERRORS;
			debug_config.BreakMask = XAUDIO2_LOG_ERRORS;
			m_xa2->SetDebugConfiguration(&debug_config);
#endif

			hr = m_xa2->CreateMasteringVoice(&m_master_voice);
			return SUCCEEDED(hr);
		}

		void SystemXA2::finalize()
		{
			if (m_master_voice != nullptr)
			{
				m_master_voice->DestroyVoice();
				m_master_voice = nullptr;
			}
			SafeRelease(&m_xa2);
		}

		void SystemXA2::process()
		{
			if (m_xa2)
			{
				HRESULT hr = m_xa2->StartEngine();
				if (FAILED(hr))
				{

				}
			}
		}

		void SystemXA2::suspend()
		{
			if (m_xa2)
			{
				m_xa2->StopEngine();
			}
		}
	}
}