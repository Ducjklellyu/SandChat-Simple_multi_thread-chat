/*
(SandChat(Simple multi-thread chat))::(Server)::(clientbase.h).

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look terms in main.c file first
*/

#pragma once

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

#include "sandchat_common.h"

void acceptclients(SOCKET Socket, SOCKET ClientsSocket[], SOCKADDR_IN clientaddr, int *nclient, _FUNCTHREAD ClientTH()); // Accept client and assign him to client structure's SOCKET.
void sendtoall(SOCKET Socket, SOCKET ClientsSocket[], int nclient, char buffer[1024]); // Send "server-message" to all clients except sender.
