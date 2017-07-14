#pragma once
#include "ThreadFun.h"
class CMainFunction :
	public CThreadFun
{
public:
	CMainFunction();
	~CMainFunction();
public:
	void  init();
};

