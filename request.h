#ifndef REQUEST_H_INCLUDED
#define REQUEST_H_INCLUDED

typedef struct Request Request;

Request* newRequest(char *name);
char* getName(Request *req);
char* toString(Request *req);

#endif // REQUEST_H_INCLUDED