/*
(SandChat(Simple multi-thread chat))::(Server)::(stringbase.c).
Ñopyright © 2017 by ducjklellyu (a.k.a Alexander Rosenthal) all rights reserved.

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

