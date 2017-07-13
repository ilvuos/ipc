#pragma once
#include "ListObject.h"
class CDoubleList :
	public CListObject
{
public:
	~CDoubleList();

public:
	int Insert(CObjectBase* Object, int position);
	int Erase (CObjectBase* Object);
	int Erase ();
	int FindObject(CObjectBase* Object);

	int GetLength() { return mLength; };

	CDoubleList()
	{
		mpRoot = new CObjectBase;
		mpRoot->mpNext = NULL;
		mpRoot->mpPrev = NULL;
		mLength = 0;
	}

protected:
	int mLength;
	CObjectBase* mpRoot;
};

