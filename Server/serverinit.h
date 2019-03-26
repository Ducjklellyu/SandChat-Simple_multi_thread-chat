/*
(SandChat(Simple multi-thread chat))::(Server)::(severinit.h).

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
void ex_BIND(SOCKET Socket, SOCKADDR_IN addr); // Setup the TCP listening SOCKET function.
void ex_LISTEN(SOCKET Socket); // Wait connection function.
