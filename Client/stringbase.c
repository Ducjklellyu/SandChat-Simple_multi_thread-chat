/*
(SandChat(Simple multi-thread chat))::(Client)::(stringbase.c)

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look stringbase.h first
*/

#define _CRT_SECURE_NO_WARNINGS

#include "stringbase.h"

void clearbuffer(char buffer[1024])
{
	buffer[strlen(buffer)] = 0;
}
