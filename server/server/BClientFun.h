#pragma once
#include "ThreadFun.h"
#include "XBroadCastClient.h"

class CBClientFun :
	public CThreadFun
{
public:
	CBClientFun();
	~CBClientFun();
protected:
	virtual void     RunThread();
	int              GetSelfIPAndPort(char *buffer);
protected:
	CXBroadCastClient mBCClient;
};

