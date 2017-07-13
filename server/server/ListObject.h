#pragma once
#include "ObjectBase.h"
class CListObject :
	public CObjectBase
{
public:
	CListObject();
	~CListObject();
public:
	void Add(CObjectBase * object);
	void Deleted(CObjectBase * object);
};

