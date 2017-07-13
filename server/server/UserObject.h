#pragma once

#include "ObjectBase.h"

class CUserObject : 
	public CObjectBase
{
public:
	CUserObject();
	~CUserObject();
protected:
	int mID; //Ψһid
	int mIP; //ip
	int mPort; //port
	int mType;// 0 server ,1 client 
	CUserObject *mpList;
public:
	void SetObjectID(int id);
	int  GetObjectID();
	int  Add(CUserObject* object );
	int  Deleted();
};

