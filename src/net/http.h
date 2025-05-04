#pragma once


#ifndef UNICODE // UNICODE
#define UNICODE // UNICODE
#endif // UNICODE


// System

#include "stdio.h"
#include "stdlib.h"


// Custom

#include "../misc.h"



// GET / HTTP/1.1\r\nHost: cbr.ru/scripts/XML_daily.aspp\r\nUser-agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:70.0) Gecko/20100101 Firefox/70.0\r\nAccept: */*\r\n\r\n\0

// Custom individual page code.
#define HTTP 0x8090


// User-Agents file name.
#define USER_AGENT_FILE_NAME (CONFIG_DIR "/user-agents")


// Default Accept method
#define HTTP_ACCEPT_DEFAULT "*/*"


// Supported http versions.
#define HTTP10 (HTTP + 01000001)
#define HTTP11 (HTTP + 01000002)
#define HTTP20 (HTTP + 01000003)


// Supported http methods.
#define HTTP_GET		 (HTTP + 02000001)
#define HTTP_POST		 (HTTP + 02000002)
#define HTTP_HEAD		 (HTTP + 02000003)
#define HTTP_OPTIONS (HTTP + 02000004)


typedef struct {
	int method;
	int version;
	int userAgent;
	int acceptType;
	char* host;
} HTTP_FRAME;


const enum {
	mozilla50windows = 1,
	chrome50windows = 2,
	opera980windows = 3
} user_agents;


const enum {
	http_http10 = 1,
	http_http11 = 2,
	http_http20 = 3
} version;


const enum {
	http_accept_default = 1
} accept_type;


#ifdef ADVANCED_HTTP // ADVANCED_HTTP


#define HTTP_DELETE (HTTP + 02000005)
#define HTTP_PUT		(HTTP + 02000006)
#define HTTP_PATCH  (HTTP + 02000007)


const enum {
	http_get = 1,
	http_post = 2,
	http_head = 3,
	http_options = 4,
	http_delete = 5,
	http_put = 6,
	http_patch = 7
} methods;


// Functions part


// Creating extended GET request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPGetRequest(char* buffer, char* hostName,const int userAgentType, const int version, const int acceptType);


// Creating extended Post request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPPostRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);


// Creating extended Head request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPHeadRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);


// Creating extended Options request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPOptionsRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);


// Creating extended Delete request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPDeleteRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);


// Creating extended Put request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPPutRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);


// Creating extended Patch request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPPatchRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);


// Creating extended Raw request and write it to the buffer. Buffer should be at least 256 bytes long. 
// If its not function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPRawRequest(char* buffer, char* hostName, const int userAgentType, const int version, const int acceptType);





#else // ADVANCED_HTTP



const enum {
	http_get = 1,
	http_post = 2,
	http_head = 3,
	http_options = 4
} methods;



// Functions part


// Creating default GET request and write it to the buffer. Buffer should be at least 256 bytes long. If its not
// function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPGetRequest(char* buffer, char* hostName, const int userAgentType, const int version);


// Creating Post request and write it to the buffer. Buffer should be at least 256 bytes long. If its not
// function will return required buffer size. Function will return -1 if something went wrong. 
int createHTTPPostRequest(char* buffer, char* hostName, const int userAgentType, const int version);


// Creating Head request and write it to the buffer. Buffer should be at least 256 bytes long. If its not
// function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPHeadRequest(char* buffer, char* hostName, const int userAgentType, const int version);


// Creating Options request and write it to the buffer. Buffer should be at least 256 bytes long. If its not
// function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPOptionsRequest(char* buffer, char* hostName, const int userAgentType, const int version);


// Creating Raw request and write it to the buffer. Buffer should be at least 256 bytes long. If its not
// function will return required buffer size. Function will return -1 if something went wrong.
int createHTTPRawRequest(char* buffer, char* hostName, const int userAgentType, const int version);



#endif // ADVANCED_HTTP



int generateHTTPFrame(char* buffer, HTTP_FRAME *httpFrame);