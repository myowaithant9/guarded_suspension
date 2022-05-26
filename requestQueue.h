#ifndef REQUESTQUEUE_H_INCLUDED
#define REQUESTQUEUE_H_INCLUDED

#include <pthread.h>
#include "request.h"

typedef struct RequestQueue RequestQueue;

RequestQueue* newRequestQueue();
Request* getRequest(RequestQueue *queue);
void putRequest(Request* req, RequestQueue *queue);

#endif // REQUESTQUEUE_H_INCLUDED