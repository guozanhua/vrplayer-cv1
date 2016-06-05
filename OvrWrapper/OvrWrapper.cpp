#include "stdafx.h"

#include <OVR_CAPI.h>

#include "OvrWrapper.h"
#include "OvrSession.h"

using namespace System;
using namespace OvrWrapper;

::OvrWrapper::OvrWrapper::OvrWrapper()
{
	auto result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result)) {
		ovrErrorInfo errorInfo;
		ovr_GetLastErrorInfo(&errorInfo);
		throw gcnew Exception(String::Format("OVR initialization failed: {}", gcnew String(errorInfo.ErrorString)));
	}
}

::OvrWrapper::OvrWrapper::~OvrWrapper()
{
	ovr_Shutdown();
}

OvrSession^ ::OvrWrapper::OvrWrapper::CreateSession()
{
	return gcnew OvrSession();
}
