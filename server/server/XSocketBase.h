#pragma once

#include <WinSock2.h>

#define X_BASE_PORT                1234 /* Port */
#define BROADCAST_UDP_PORT          X_BASE_PORT /* Port that will be opened */
#define CLIENT_TCP_PORT             X_BASE_PORT + 1 /* Max number of bytes of data */
#define MAXDATASIZE 100                 /* Max number of bytes of data */

class CXSocketBase
{
public:
	CXSocketBase();
	~CXSocketBase();
public:
	virtual int Create() = 0;
protected:
	int mSockfd;

};

