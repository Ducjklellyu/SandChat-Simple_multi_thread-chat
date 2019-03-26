/*
(SandChat(Simple multi-thread chat))::(Server)::(stringbase.c).

GitHub profile - "https://github.com/ducjklellyu".
Telegram - "@Sunuia".

!!!
Look stringbase.h first
*/

#define _CRT_SECURE_NO_WARNINGS

#include "stringbase.h"

void createmessage(char namebuffer[1024], char buffer[1024], char fullbuffer[1024])
{
	strcpy(fullbuffer, namebuffer);
	strcat(fullbuffer, ":");
	strcat(fullbuffer, buffer);
}

