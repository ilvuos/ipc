#pragma once
#include "ThreadFun.h"
#include "SUserConfig.h"
#include "DoubleList.h"

class CSettingFun :
	public CThreadFun
{
public:
	CSettingFun();
	~CSettingFun();
protected:
	CSUserConfig *mpSuserConfig;
	CDoubleList  *mpUserList;
public:
	int Init();
};

