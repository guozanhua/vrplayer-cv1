// This is the main DLL file.

#include "stdafx.h"

#include "OvrWrapper.h"

void OvrWrapper::Ovr::Initialize()
{
	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
	{
		throw gcnew Exception("Failed to initialize libOVR");
	}
}

void OvrWrapper::Ovr::Shutdown()
{
	ovr_Shutdown();
}
