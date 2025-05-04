#include "misc.h"



int isCharaterNumber(const char* character) {
	switch (*character)
	{
	case '0':
		return 0;
	case '1':
		return 0;
	case '2':
		return 0;
	case '3':
		return 0;
	case '4':
		return 0;
	case '5':
		return 0;
	case '6':
		return 0;
	case '7':
		return 0;
	case '8':
		return 0;
	case '9':
		return 0;
	default:
		return 1;
	}
}


int getCharArrayLength(char *array) {
	int counter = 0;
	for (; array[counter] != '\0'; ++counter);
	return counter;
}


int getCharArrayLengthNClean(char *array) {
	int counter = 0;
	for (; array[counter] != '\0'; ++counter) { array[counter] = ' '; }
	return counter;
}


int stringToCharBuffer(char *string, char *buffer) {
	int stringLength = getCharArrayLength(string);
	int bufferLength = getCharArrayLength(buffer);
	if (stringLength >= bufferLength) {
		return 1;
	}
	for (int counter = 0; counter != stringLength; ++counter) {
		buffer[counter] = string[counter];
 	}
	return 0;
}


int addWordToCharBuffer(char* buffer, char* word, int iStart) {
	int wordLength = getCharArrayLength(word);
	int counter = 0;
	for(; counter != wordLength;){ 
		buffer[iStart] = word[counter];
		++counter;
		++iStart;
	}
	return 0;
}