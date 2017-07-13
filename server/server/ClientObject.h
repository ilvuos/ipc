#pragma once
#include "UserObject.h"
class CClientObject :
	public CUserObject
{
public:
	CClientObject();
	~CClientObject();
protected:
	CUserObject *mpServerList;
};

