#include "stdafx.h"
#include "MonitorFun.h"


CMonitorFun::CMonitorFun()
{
}


CMonitorFun::~CMonitorFun()
{
}

void   CMonitorFun::RunThread()
{
	//接收监听数据
	int  nRet = 0;
	char buffer[100];
	nRet = mBroadCast.Create();
	while (!nRet)
	{
		nRet = mBroadCast.Recvfrom(buffer,100);
	}
	mBroadCast.Close();
	mbExist = false;
	return;
}