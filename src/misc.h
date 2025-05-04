#pragma once


#ifndef UNICODE // UNICODE
#define UNICODE // UNICODE
#endif // UNICODE


// Custom individual page code.
#define MISCELLANEOUS 0x9090



// Identify wether character is number(return 0) or not(return 1)
// Seem useless for me either btw.
int isCharaterNumber(const char* character);


// <May be optimized>
// Very depends on '\0' symbol wich may cause issues.
int getCharArrayLength(char *array);


// Same as previous but fill whole array with space symbol.
// Cause heap corruptions. TODO: fix.
int getCharArrayLengthNClean(char* array);


// <May be easy optimized>
// This function has some error codes for debug to be easier.
// 0 - Operation was done successfully.
// 1 - Buffer has not enough space for string & '\0' character. Additional space for '\0' character guarantee \
// less issues with this function either as more reliability and security.
int stringToCharBuffer(char *string, char *buffer);


// Adding some word to buffer with iStart index as a beggining.
int addWordToCharBuffer(char *buffer, char *word, int iStart);