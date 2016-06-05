#pragma once

#include <OVR_CAPI.h>

using namespace System;
using namespace System::Windows::Media::Media3D;

namespace OvrWrapper
{
	public ref class OvrSession
	{
	internal:
		OvrSession();
	public:
		~OvrSession();
		void PrintResolution();
		Nullable<Quaternion> GetTrackingState();
	private:
		ovrSession session;
		ovrGraphicsLuid *luid;
	};
}
