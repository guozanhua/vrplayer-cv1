#pragma once
#pragma comment(lib, "LibOVR")

#include "OvrSession.h"

namespace OvrWrapper
{
	public ref class OvrWrapper
	{
	public:
		OvrWrapper();
		~OvrWrapper();
		OvrSession^ CreateSession();
	};
}
