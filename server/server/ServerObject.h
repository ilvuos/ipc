#pragma once
#include "UserObject.h"
class CServerObject :
	public CUserObject
{
public:
	CServerObject();
	~CServerObject();
protected:
	CUserObject *mpClientList;
};

