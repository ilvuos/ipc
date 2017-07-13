#include "stdafx.h"
#include "UserObject.h"


CUserObject::CUserObject()
{
	mID = -1;
}


CUserObject::~CUserObject()
{
}

void CUserObject::SetObjectID(int id)
{
	mID = id;
}
int  CUserObject::GetObjectID()
{
	return mID;
}
