#include "stdafx.h"
#include "XUdpSocket.h"


CXUdpSocket::CXUdpSocket()
{
}


CXUdpSocket::~CXUdpSocket()
{
}

int   CXUdpSocket::Close()
{
	if (mSockfd)
		closesocket(mSockfd);
	return 0;
}