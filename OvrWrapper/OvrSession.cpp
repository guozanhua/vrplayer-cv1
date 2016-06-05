#include "stdafx.h"

#include <windows.h>
#include <cstdio>
#include <memory>

#include "OvrSession.h"

using namespace std;

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::Media::Media3D;
using namespace OvrWrapper;

static void GetHmdDesc(ovrSession session, ovrHmdDesc& desc)
{
	// this is necessary because ovr_GetHmdDesc returns an aligned struct on the stack
	desc = ovr_GetHmdDesc(session);
}

void OvrSession::PrintResolution()
{
	shared_ptr<ovrHmdDesc> desc(new ovrHmdDesc); // this needs to be on the heap because it is aligned
	GetHmdDesc(this->session, *desc);
	ovrSizei* resolution = &desc->Resolution;

	//Debug::WriteLine("w = {} h = {}", resolution->w, resolution->h);
}

static void GetTrackingState(ovrSession session, ovrTrackingState& state)
{
	state = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
}

Nullable<Quaternion> OvrSession::GetTrackingState()
{
	shared_ptr<ovrTrackingState> ts(new ovrTrackingState);
	::GetTrackingState(this->session, *ts);

	if (ts->StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
	{
		auto& q = ts->HeadPose.ThePose.Orientation;
		return Nullable<Quaternion>(Quaternion(q.x, q.y, q.z, q.w));
	}

	return Nullable<Quaternion>();
}

OvrSession::OvrSession()
{
	ovrSession session;
	this->luid = new ovrGraphicsLuid;
	auto result = ovr_Create(&session, this->luid);
	if (OVR_FAILURE(result))
	{
		throw gcnew Exception("Cannot create OVR session.");
	}
	this->session = session;
}

OvrSession::~OvrSession()
{
	ovr_Destroy(this->session);
}
