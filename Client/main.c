/*
(SandChat(Simple multi-thread chat))::(Client)::(main.c)

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

*/

#pragma comment(lib,"Ws2_32.lib")

#include <stdio.h>
#include <stdlib.h>

#include <winsock2.h>
#include <windows.h>

#include "clientinit.h"
#include "stringbase.h"
#include "sandchat_common.h"

DWORD WINAPI ClientTH(LPVOID Socket);

int main()
{
	SOCKET Socket;
	SOCKADDR_IN local_addr;
	DWORD ID;

	char WSABuff[1024];
	char inputbuffer[1024]; // Buffer to input message.

	start_WSA(*(WSADATA*)&WSABuff[0]);
	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Set SOCKET parameters.
	ex_SOCKET(Socket); 
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(2309); 
	local_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Set IP number:localhost(127.0.0.1)
	ex_CONNECT(Socket, local_addr);
	
	_GET(&inputbuffer[0]);
	send(Socket, &inputbuffer[0], sizeof(inputbuffer), 0);
	_CLEARBUFF(inputbuffer[0]);
	
	CreateThread(NULL, 0, ClientTH, &Socket, 0, &ID);
	while ((strcmp(&inputbuffer[0], "_exit") != 0))
	{
		_CLEARBUFF(inputbuffer[bytes_recv]);
		_GET(&inputbuffer[0]);
		send(Socket, &inputbuffer[0], sizeof(inputbuffer), 0);
	}
	printf("Exit\n");
	closesocket(Socket);
	WSACleanup();
	return 0;
}

DWORD WINAPI ClientTH(LPVOID Socket)
{ 
	SOCKET Client_Socket;
	Client_Socket = ((SOCKET *)Socket)[0];
	char buffer[1024]; // Buffer to accept message.
	while ((bytes_recv = recv(Client_Socket, &buffer[0], sizeof(buffer), 0)) && bytes_recv != SOCKET_ERROR)
	{
		printf("%s\n", buffer);
		_CLEARBUFF(buffer[bytes_recv]);
	}
	printf("Connection with:'%s',has been lost\n", "127.0.0.1");
	closesocket(Client_Socket);
	WSACleanup();
	return 0;
}
