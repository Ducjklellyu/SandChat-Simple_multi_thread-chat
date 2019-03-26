/*
(SandChat(Simple multi-thread chat))::(Server)::(clientbase.c).

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look clientbase.h first
*/

#define _WINSOCK_DEPRECATED_NO_WARNING

#include "clientbase.h"

void acceptclients(SOCKET Socket, SOCKET ClientsSocket[], SOCKADDR_IN clientaddr, int *nclient, _FUNCTHREAD ClientTH())
{

	int clientaddrsize = sizeof(clientaddr);

	while (ClientsSocket[*nclient] = accept(Socket, (SOCKADDR *)&clientaddr, &clientaddrsize))
	{
		_beginthreadex(0, 0, ClientTH, (void*)&ClientsSocket[*nclient], 0, 0); // Create thread for client
		_ADDUSR(*nclient);
	}
	return 0;
}

void sendtoall(SOCKET Socket, SOCKET ClientsSocket[], int nclient, char buffer[1024])
{
	for (int i = 0; i < nclient; i++)
	{
		if (Socket != ClientsSocket[i])
		{
			send(ClientsSocket[i], &buffer[0], strlen(buffer), 0);
		}
	}
	return 0;
}
