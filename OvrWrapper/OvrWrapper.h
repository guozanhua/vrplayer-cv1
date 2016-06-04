// OvrWrapper.h

#pragma once
#include <OVR_CAPI.h>

#pragma comment(lib, "LibOVR")

using namespace System;

namespace OvrWrapper
{
	public ref class Ovr abstract sealed
	{
	public:
		static void Initialize();
		static void Shutdown();
	};
}
