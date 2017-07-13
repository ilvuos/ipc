#include "stdafx.h"
#include "XBroadCastServer.h"


CXBroadCastServer::CXBroadCastServer()
{
	mSockfd = 0;
}

CXBroadCastServer::~CXBroadCastServer()
{

}

int  CXBroadCastServer::Create()
{
	// 创建socket 
	int nRet = 0;
	mSockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == mSockfd)
	{
		TRACE(" error! error code is %d/n", WSAGetLastError());
		return -1;
	}
	// 用来绑定套接字 
	SOCKADDR_IN sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(BROADCAST_UDP_PORT);
	sin.sin_addr.s_addr = 0;

	// 用来从网络上的广播地址接收数据 
	mSin_from.sin_family = AF_INET;
	mSin_from.sin_port = htons(BROADCAST_UDP_PORT);
	mSin_from.sin_addr.s_addr = INADDR_BROADCAST;
	//设置该套接字为广播类型， 
	bool bOpt = true;
	setsockopt(mSockfd, SOL_SOCKET, SO_BROADCAST, (char*)&bOpt, sizeof(bOpt));
	// 绑定套接字 
	nRet = bind(mSockfd, (SOCKADDR*)&sin, sizeof(SOCKADDR));
	if (SOCKET_ERROR == nRet)
	{
		TRACE("bind  error! error code is %d/n", WSAGetLastError());
		return -1;
	}
	return 0;
}

int  CXBroadCastServer::Recvfrom(char *buff,int length)
{
	int nAddrLen = sizeof(SOCKADDR);
	// 接收数据
	int nSendSize = recvfrom(mSockfd, buff, length, 0, (SOCKADDR*)&mSin_from, &nAddrLen);
	if (SOCKET_ERROR == nSendSize)
	{
		TRACE("recvfrom  error! error code is %d/n", WSAGetLastError());
		return -1;
	}
	TRACE("Recv: %s/n", buff);
	return 0;
}

