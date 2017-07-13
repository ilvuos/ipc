#include "stdafx.h"
#include "BClientFun.h"


CBClientFun::CBClientFun()
{
}


CBClientFun::~CBClientFun()
{
}

int CBClientFun::GetSelfIPAndPort(char *buffer)
{
    char host_name[225];
	struct addrinfo hints;
	struct addrinfo *res;
	struct sockaddr_in *addr;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;    /* Allow IPv4 */
	hints.ai_flags = AI_PASSIVE;  /* For wildcard IP address */
	hints.ai_protocol = 0;        /* Any protocol */
	hints.ai_socktype = SOCK_STREAM;

	memset(buffer, 0, 32);
    if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR)
    {
		TRACE("get ip fiale.... \r\n");
		return NULL;
    }
	getaddrinfo(host_name, NULL, &hints, &res);   //利用主机名称获取本地地
	addr = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(AF_INET,&addr->sin_addr, buffer, 16);
	freeaddrinfo(res);

	return 0;

}

void   CBClientFun::RunThread()
{
	//接收监听数据
	int  nRet = 0;
	char buffer[100];
	nRet = mBCClient.Create();

	memset(buffer,0x33,100);
	while (!nRet)
	{
		GetSelfIPAndPort(buffer);
		nRet = mBCClient.SendData(buffer, 100);
		Sleep(1000);
	}
	mBCClient.Close();
	mbExist = false;
	return;
}