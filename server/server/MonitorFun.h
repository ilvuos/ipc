#pragma once
#include "ThreadFun.h"
#include "XBroadCastServer.h"
// ¼à¿Ø client Á¬½Ó
class CMonitorFun :
	public CThreadFun 
{
public:
	CMonitorFun();
	~CMonitorFun();
protected:
	virtual void     RunThread();
protected:
	CXBroadCastServer mBroadCast;
};

