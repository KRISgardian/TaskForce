#include "http.h"







#ifdef ADVANCED_HTTP // ADVANCED_HTTP



// ADVANCED_HTTP



#else // ADVANCED_HTTP



int createHTTPGetRequest(char* buffer, char* hostName, const int userAgentType, const int version) {

	HTTP_FRAME *httpFrame = malloc(sizeof(HTTP_FRAME));

	if (httpFrame == NULL) {
		free(httpFrame);
		return GetLastError();
	}

	httpFrame->acceptType = http_accept_default;
	httpFrame->host		    = hostName;
	httpFrame->method	    = http_get;
	httpFrame->userAgent  = userAgentType;
	httpFrame->version    = version;



	free(httpFrame);
	return 0;
}


// GET / HTTP/1.1\r\nHost: 22cbr.ru/scripts/XML_daily.aspp\r\nUser-agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:70.0) Gecko/20100101 Firefox/70.0\r\nAccept: */*\r\n\r\n\0

// Method
// Version
// HostName
// UserAgent
// AcceptType


int generateHTTPFrame(char* buffer, HTTP_FRAME *httpFrame) {

	// Determining which method is using in http request. Also filling buffer with this method name, requested server directory and protocol name.
	switch (httpFrame->method){
	case http_get:
		addWordToCharBuffer(buffer, "GET / HTTP/", 0);
		break;
	case http_post:
		addWordToCharBuffer(buffer, "POST / HTTP/", 0);
		break;
	case http_head:
		addWordToCharBuffer(buffer, "HEAD / HTTP/", 0);
		break;
	case http_options:
		addWordToCharBuffer(buffer, "OPTIONS / HTTP/", 0);
		break;
	default:
		addWordToCharBuffer(buffer, "GET / HTTP/", 0);
		break;
	}

	// Determining which version is to use and stick it together with buffer and host name.
	switch (httpFrame->version) {
	case http_http10:
		addWordToCharBuffer(buffer, "1.0\r\nHost: ", 11);
		addWordToCharBuffer(buffer, httpFrame->host, 22);
		break;
	case http_http11:
		addWordToCharBuffer(buffer, "1.1\r\nHost: ", 11);
		addWordToCharBuffer(buffer, httpFrame->host, 22);
		break;
	case http_http20:
		addWordToCharBuffer(buffer, "2.0\r\nHost: ", 11);
		addWordToCharBuffer(buffer, httpFrame->host, 22);
		break;
	default:
		addWordToCharBuffer(buffer, "1.1\r\nHost: ", 11);
		addWordToCharBuffer(buffer, httpFrame->host, 22);
		break;
	}

	// Determining which userAgent type to use and finalize the http record.
	

}

// TODO: There's tone of functions that i need to write. So... to do.


#endif // ADVANCED_HTTP