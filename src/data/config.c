#include "config.h"








#ifdef ADVANCED_CONFIG // ADVANCED_CONFIG



// TODO: Create functions primitives for ADVANCED_CONFIG macros.



#else ADVANCED_CONFIG // ADVANCED_CONFIG



int readAllFromConfigFile(char* configFileName, char* buffer) {

	// No need to allocate it properly cause CloseHandle() will clear res anyway.
	HANDLE hFile = CreateFile(configFileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		CloseHandle(hFile);
		return GetLastError();
	}

	LARGE_INTEGER* largeIntStruct = malloc(sizeof(LARGE_INTEGER));

	if (largeIntStruct == NULL) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	if (!GetFileSizeEx(hFile, &largeIntStruct->QuadPart)) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	int bufferSize = getCharArrayLength(buffer);

	if (largeIntStruct->QuadPart >= bufferSize) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return 1;
	}

	free(largeIntStruct);

	LPDWORD bytesCounter = 0;

	if (!ReadFile(hFile, buffer, (DWORD)bufferSize, bytesCounter, NULL)) {
		CloseHandle(hFile);
		return GetLastError();
	}

	CloseHandle(hFile);
	return 0;
}


int readAllFromConfgiFileEx(char* configFileName, char* buffer) {

	HANDLE hFile = CreateFile(configFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		CloseHandle(hFile);
		return GetLastError();
	}

	LARGE_INTEGER* largeIntStruct = malloc(sizeof(LARGE_INTEGER));

	if (largeIntStruct == NULL) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	if (!GetFileSizeEx(hFile, &largeIntStruct->QuadPart)) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	int bufferSize = getCharArrayLength(buffer);

	LPDWORD bytesCounter = 0;

	if (!ReadFile(hFile, buffer, (DWORD)bufferSize, bytesCounter, NULL)) {
		CloseHandle(hFile);
		return GetLastError();
	}
	CloseHandle(hFile);
	if (largeIntStruct->QuadPart >= bufferSize) {
		return (largeIntStruct->QuadPart - bufferSize);
	}
	free(largeIntStruct);
	return 0;
}


int readFirstLineFromConfigFile(char* configFileName, char* buffer) {

	HANDLE hFile = CreateFile(configFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		CloseHandle(hFile);
		return GetLastError();
	}

	LARGE_INTEGER* largeIntStruct = malloc(sizeof(LARGE_INTEGER));

	if (largeIntStruct == NULL) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	if (!GetFileSizeEx(hFile, &largeIntStruct->QuadPart)) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	int bufferSize = getCharArrayLength(buffer);

	LPDWORD bytesCounter = 0;

	if (!ReadFile(hFile, buffer, (DWORD)bufferSize, bytesCounter, NULL)) {
		CloseHandle(hFile);
		free(largeIntStruct);
		return GetLastError();
	}

	CloseHandle(hFile);
	free(largeIntStruct);

	int counter = 0;

	// Reading buffer until first '\0' & then fill left buffer with space symbol.
	for (; buffer[counter] != '\0'; ++counter);
	for (; buffer[counter] != '\0'; ++counter) {
		buffer[counter] = ' ';
	}
	return 0;
}



#endif // ADVANCED_CONFIG