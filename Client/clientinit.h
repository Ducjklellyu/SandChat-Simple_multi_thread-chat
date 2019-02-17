/*
(SandChat(Simple multi-thread chat))::(Client)::(clientinit.h)
Ñopyright © 2017 by ducjklellyu (a.k.a Alexander Rosenthal) all rights reserved.

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

*/

#pragma once

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

void start_WSA(WSADATA WSAdata); // Initialize WINSOCK library function.
void ex_SOCKET(SOCKET Socket); // Create SOCKET function.
void ex_CONNECT(SOCKET Socket, SOCKADDR_IN addr); // Connect to server function.