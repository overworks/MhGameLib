#ifndef	_MH_RESOURCE_SOUND_HPP_
#define	_MH_RESOURCE_SOUND_HPP_

#include <mh/util.hpp>

namespace Mh
{
	namespace Resource
	{
		class Sound //: public Object
		{
		public:
			Sound();
			virtual ~Sound();
		};
		
		/*
		 *	사운드 리소스 관리자
		 */
		class SoundManager : public Singleton<SoundManager>
		{
		public:
			SoundManager();
			~SoundManager();
		};

	}	// namespace Mh::Resource
}		// namespace Mh

#endif	/* _MH_RESOURCE_SOUND_HPP_ */