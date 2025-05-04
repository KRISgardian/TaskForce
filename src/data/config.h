#pragma once


#ifndef UNICODE // UNICODE
#define UNICODE // UNICODE
#endif // UNICODE


// System

#include <windows.h>
#include <fileapi.h>


// Custom

#include "../misc.h"



// Custom individual page code.
#define CONFIG 0x7090


#ifdef ADVANCED_CONFIG // ADVANCED_CONFIG

const enum {
	config_Text = 1,
	config_Ini  = 2,
	config_XML  = 3,
	config_json = 4
} config_type;

#else // ADVANCED_CONFIG

const enum {
	config_Text = 1
} config_type;



// Functions part



// Reading all data from file by given file name into buffer. Returning 0
// if function exit successfully, 1 otherwise. Could also return GetLastError()
// value. Buffer should be enough size to read all from file by one time.
int readAllFromConfigFile(char *configFileName, char *buffer);


// Extended version of the previous function. This one don't need a buffer
// with the same size as a file. If buffer could not handle all file size
// number of not wroten bytes will return. Otherwise returning 0 if function
// exit successfully.
int readAllFromConfgiFileEx(char *configFileName, char *buffer);


// Reading first line(by the '\0' symbol) from file. Buffer should be
// enough size to contain all data, otherwise function will exit
// with error code 1. Returning 0 if everything was fine.
int readFirstLineFromConfigFile(char *configFileName, char *buffer);


#endif // ADVANCED_CONFIG