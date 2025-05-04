//#include "../src/net/net-cs.h"
//#include "../src/data/data-updater.h"


#ifndef UNICODE // UNICODE
#define UNICODE // UNICODE
#endif // UNICODE


#define WIN32_LEAN_AND_MEAN // This shit is a freakin plug cause Windows cause issues without this one.

#define _CRT_SECURE_NO_WARNINGS // FUCK MICROSOFT.

#pragma comment(lib, "Ws2_32.lib") // And this one is a plug either. Same reason. Linux is better.

#pragma warning(suppress : 4133)


// Ethernet

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>


// System

#include <stdio.h>
#include <stdlib.h>
#include <fileapi.h>


// Custom

#include "../src/data/config.h"
//#include "../src/net/net-cs.h"


#ifndef CONFIG_DIR //CONFIG_DIR
#define CONFIG_DIR "config" //CONFIG_DIR
#endif //CONFIG_DIR


// Custom individual page code.
#define GUIPLUG 0x10101090


int main() {
	char *cPointer = malloc(11 * sizeof(char));
	if (readAllFromConfigFile(L"D:\\TaskForce\\user-agents", cPointer) != 0) {
		printf("Pizdec\n");
		return 1;
	}
	printf("%s\n", cPointer);
	free(cPointer);
	return 0;
}