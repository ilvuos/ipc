#pragma once
class CObjectBase
{
public:
	CObjectBase();
	~CObjectBase();
public:
	CObjectBase *mpNext;
	CObjectBase *mpPrev;
};

