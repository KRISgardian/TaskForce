#pragma once


#ifndef UNICODE // UNICODE
#define UNICODE // UNICODE
#endif // UNICODE


#define WIN32_LEAN_AND_MEAN // This shit is a freakin plug cause Windows cause issues without this one.

#define _CRT_SECURE_NO_WARNINGS // FUCK MICROSOFT.

#pragma comment(lib, "Ws2_32.lib") // And this one is a plug either. Same reason. Linux is better.



// System

#include <windows.h>


// Ethernet

#include <winsock2.h>
#include <ws2tcpip.h>



// Custom

#include "http.h"


// Custom individual page code.
#define NETCLIENTSERVER 0x101090