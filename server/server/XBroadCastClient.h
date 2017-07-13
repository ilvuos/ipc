#pragma once
#include "XUdpSocket.h"
class CXBroadCastClient :
	public CXUdpSocket
{
public:
	CXBroadCastClient();
	~CXBroadCastClient();
protected:
	SOCKADDR_IN       mSin_in;
public:
	int   Create();
	int   SendData(char *buff, int length);
};

