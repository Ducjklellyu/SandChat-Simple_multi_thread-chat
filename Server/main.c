/*
(SandChat(Simple multi-thread chat))::(Server)::(main.c).
Copyright © 2017 by ducjklellyu (a.k.a Alexander Rosenthal) all rights reserved.

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look .h files first.
!!!

!!!Terms!!!

Terms are points by this charter ".

"client name" it's text which accepts from client and saves while client is on-line.
"message" it's text which accepts from client and changes all time when client sends texts.
"server message" it's buffer which have "client name" and charter : and "message",it's changes after new "message".

!!!Terms!!!
*/

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

#include "serverinit.h"
#include "clientbase.h"
#include "stringbase.h"
#include "sandchat_common.h"

int nclients = 0; // Clients counter.

int bytes_recv; // Variable which save returned recv value.

SOCKET Socket;
SOCKET ClientsSocket[1024];
SOCKADDR_IN client_addr;
WSADATA WSAdata;
SOCKADDR_IN local_addr;

_FUNCTHREAD ClientTH (void* data); // Client thread function.

int main()
{
	start_WSA(WSAdata);
	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	ex_SOCKET(Socket);
	// -> addr
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(2309);
	local_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Set destination IP number:localhost(127.0.0.1).
	// addr -<
	ex_BIND(Socket, local_addr);
	ex_LISTEN(Socket);
	acceptclients(Socket, &ClientsSocket, client_addr, &nclients, &ClientTH);
	return 0;
}

_FUNCTHREAD ClientTH(void* data) // Client thread configuration.
{
	SOCKET* initclient = (SOCKET*)data;
	SOCKET Client = *initclient; // With this SOCKET work with client.

	char buffer[1024]; // Buffer for save "server message".
	char messagebuffer[1024]; // Buffer for save "message".
	char namebuffer[1024]; // Buffer for save "client name"

	while ((bytes_recv = recv(Client, &namebuffer[0], sizeof(namebuffer), 0)) && bytes_recv != SOCKET_ERROR)
	{
		if (bytes_recv > 0) // If bytes accepted currently.
			break;
	}

	printf("User '%s' has connected!\n", namebuffer);

	while ((bytes_recv = recv(Client, &messagebuffer[0], sizeof(messagebuffer), 0)) && bytes_recv != SOCKET_ERROR) 
	{
		_CLEARBUFF(buffer[0]);
		createmessage(namebuffer, messagebuffer, buffer);
		sendtoall(Client, ClientsSocket, nclients, buffer);
	}

	printf("User '%s' has disconnected!\n", namebuffer);

	_DELUSR(nclients);
	closesocket(Client);
	return -1;
}
