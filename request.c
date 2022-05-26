#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "request.h"

typedef struct Request {
    char name[64];
} Request;

Request* 
newRequest(char *name)
{
    Request *req = malloc(sizeof(Request));
    strcpy(req->name, name);
    return req;
}
char* 
getName(Request *req)
{
    return req->name;
}

char* 
toString(Request *req)
{
    static char msg[128];
    sprintf(msg, "[ Request %s ] ", getName(req));
    return msg;
}
