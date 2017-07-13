#include "stdafx.h"
#include "XBroadCastClient.h"


CXBroadCastClient::CXBroadCastClient()
{
}


CXBroadCastClient::~CXBroadCastClient()
{
}

int  CXBroadCastClient::Create()
{
	/* Creating UDP socket */
	if ((mSockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		/* handle exception */
		TRACE("Creating socket failed.");
		return -1;
	}

	mSin_in.sin_family = AF_INET;
	mSin_in.sin_port = htons(BROADCAST_UDP_PORT);
	mSin_in.sin_addr.s_addr = INADDR_BROADCAST;
	bool bOpt = true;
	//设置该套接字为广播类型 
	setsockopt(mSockfd, SOL_SOCKET, SO_BROADCAST, (char*)&bOpt, sizeof(bOpt));
	return 0;
}

int   CXBroadCastClient::SendData(char *buff, int length)
{
	if(mSockfd)
	{
		// 发送数据 
		int nSendSize = sendto(mSockfd, buff, length, 0, (SOCKADDR*)&mSin_in, sizeof(SOCKADDR));
		if (SOCKET_ERROR == nSendSize)
		{
			TRACE(" error!, error code is %d/n", WSAGetLastError());
			return -1;
		}
	}
	return 0;
}
