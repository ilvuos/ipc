#include "stdafx.h"
#include "DoubleList.h"


CDoubleList::~CDoubleList()
{
	Erase();
	delete mpRoot;
	mpRoot = NULL;
}

int CDoubleList::Insert(CObjectBase* Object, int position)
{
	int i = 0;
	//�ж��Ƿ�λ�ò���
	if (position >= mLength)
		position = 0;
	//�ҵ���ǰλ��
	CObjectBase* pCurrent = mpRoot->mpNext;
	for (i = 0; i < position; i++)
	{
		pCurrent = pCurrent->mpNext;
	}
	//ǰ�����㷨
	Object->mpNext = pCurrent;
	Object->mpPrev = pCurrent->mpPrev;
	pCurrent->mpPrev->mpNext = Object;
	pCurrent->mpPrev = Object;
	
	mLength++;
	return 0;
}

int CDoubleList::Erase(CObjectBase* Object)
{
	if (mLength)
	{
		Object->mpPrev->mpNext = Object->mpNext;
		Object->mpNext->mpPrev = Object->mpPrev;
		delete Object;
	}
	return 0;
}

int CDoubleList::Erase()
{
	while (mpRoot->mpNext != mpRoot->mpPrev)
	{
		Erase(mpRoot->mpNext);
	}
	return 0;
}

int CDoubleList::FindObject(CObjectBase* Object)
{
	CObjectBase* pCurrent = mpRoot->mpNext;
	while (pCurrent->mpNext != mpRoot)
	{
		if (pCurrent == Object) {
			return 0;
		}
		pCurrent = pCurrent->mpNext;
	}
	return -1;
}