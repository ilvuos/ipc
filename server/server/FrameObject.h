#pragma once
#include "ObjectBase.h"
#define INIT  0xffffffffL  
#define XOROT 0xffffffffL  


class CFrameObject :
	public CObjectBase
{
public:
	CFrameObject();
	~CFrameObject();
public:
	virtual BYTE *GetFrame() { return mpFrame; };
	virtual void  MakeHeader(int type);
	virtual void  MakeHeader(int type, int length) ;
	virtual int  MakeFrame(BYTE *data, int length) ;
protected:
	 int mType;
	 int mLength;
	 int CRC(BYTE *buffer, int length);
protected:
	BYTE *mpFrame;
};

