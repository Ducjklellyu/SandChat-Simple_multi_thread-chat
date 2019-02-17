/*
(SandChat(Simple multi-thread chat))::(Client)::(main.c)
Ñopyright © 2017 by ducjklellyu (a.k.a Alexander Rosenthal) all rights reserved.

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"Ws2_32.lib")

#include <winsock2.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

#include "clientinit.h"
#include "stringbase.h"
#include "sandchat_common.h"

int bytes_recv; // Variable to save recv returned value.

SOCKET Socket;
WSADATA WSAdata;
SOCKADDR_IN local_addr;

_FUNCTHREAD ClientTH();

int main()
{
	char inputbuffer[1024]; // Buffer to input message.

	start_WSA(WSAdata);
	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Set SOCKET parameters.
	ex_SOCKET(Socket); 
	// -> addr
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(2309); 
	local_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Set IP number:localhost(127.0.0.1)
	// addr -<
	ex_CONNECT(Socket, local_addr);

	fgets(&inputbuffer[0], sizeof(inputbuffer), stdin);
	send(Socket, &inputbuffer[0], sizeof(inputbuffer), 0);
	_CLEARBUFF(inputbuffer[0]);

	_beginthreadex(0, 0, ClientTH, 0, 0, 0);
	while (1)
	{
		_CLEARBUFF(inputbuffer[bytes_recv]);
		fgets(&inputbuffer[0], sizeof(inputbuffer), stdin);
		if (strcmp(&inputbuffer[0], "_exit") == 0)
			break;
		send(Socket, &inputbuffer[0], sizeof(inputbuffer), 0);
	}
	printf("Exit\n");
	closesocket(Socket);
	WSACleanup();
	return -1;
}

_FUNCTHREAD ClientTH()
{ 
	char buffer[1024]; // Buffer to accept message.
	while ((bytes_recv = recv(Socket, &buffer[0], sizeof(buffer), 0)) && bytes_recv != SOCKET_ERROR)
	{
		_CLEARBUFF(buffer[bytes_recv]);
		printf("%s\n", buffer);
	}
	printf("Connection with:'%s',has been lost\n", "127.0.0.1");
	closesocket(Socket);
	WSACleanup();
	return -1;
}
