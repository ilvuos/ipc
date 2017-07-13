#pragma once
#include "XSocketBase.h"
class CXUdpSocket :
	public CXSocketBase
{
public:
	CXUdpSocket();
	~CXUdpSocket();
public:
	int   Close();
};

