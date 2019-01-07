#ifndef	_MH_RESOURCE_GPU_PROGRAM_
#define	_MH_RESOURCE_GPU_PROGRAM_

#include "base.hpp"

namespace Mh
{
	namespace Resource
	{
		/*
		 *	GPU 프로그램(셰이더등...)
		 */
		class GPUProgram : public Base
		{
		public:
			GPUProgram();
			virtual ~GPUProgram();

		};

	}	// namespace Mh::Resource
}		// namespace Mh

#endif	/* _MH_RESOURCE_GPU_PROGRAM_ */