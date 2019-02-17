/*
(SandChat(Simple multi-thread chat))::(Server)::(serverinit.c).
Ñopyright © 2017 by ducjklellyu (a.k.a Alexander Rosenthal) all rights reserved.

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look severinit.h first
*/

#define _WINSOCK_DEPRECATED_NO_WARNING

#include "serverinit.h"

void start_WSA(WSADATA WSAdata)
{
	if (WSAStartup(0x0202, &WSAdata))
	{
		printf("Error WSASTARTUP doesn't exist,Error:%d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	return 0;
}

void ex_SOCKET(SOCKET Socket)
{
	if (Socket==SOCKET_ERROR)
	{
		printf("Error SOCKET doesn't exist,Error:%d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	return 0;
}

void ex_BIND(SOCKET Socket, SOCKADDR_IN addr)
{
	if (bind(Socket, (SOCKADDR*)&addr, sizeof(addr)))
	{
		printf("Error BIND doesn't exist,Error:%d\n", WSAGetLastError());
		closesocket(Socket);
		WSACleanup();
		return -1;
	}
	return 0;
}

void ex_LISTEN(SOCKET Socket)
{
	if (listen(Socket, SOMAXCONN))
	{
		printf("Error LISTEN doesn't exist,Error:%d\n", WSAGetLastError());
		closesocket(Socket);
		WSACleanup();
		return -1;
	}
	return 0;
}

