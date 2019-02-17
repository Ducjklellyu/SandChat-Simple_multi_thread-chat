/*
(SandChat(Simple multi-thread chat))::(Client)::(clientinit.c)
Ñopyright © 2017 by ducjklellyu (a.k.a Alexander Rosenthal) all rights reserved.

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look clientinit.h first
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "clientinit.h"

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
	if (Socket == SOCKET_ERROR)
	{
		printf("Error SOCKET doesn't exist,Error:%d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	return 0;
}

void ex_CONNECT(SOCKET Socket, SOCKADDR_IN addr)
{
	if (connect(Socket, (SOCKADDR*)&addr, sizeof(SOCKADDR_IN)))
	{
		printf("CONNECT doesn't exist,Error:%d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}	
	return 0;
}
