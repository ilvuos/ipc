#pragma once
#include "XUdpSocket.h"

class CXBroadCastServer :
	public CXUdpSocket
{
public:
	CXBroadCastServer();
	~CXBroadCastServer();
protected:
	SOCKADDR_IN       mSin_from;
public:
	int   Create();
	int   Recvfrom(char *buff, int length);
};

