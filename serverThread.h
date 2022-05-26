#ifndef SERVERTHREAD_H_INCLUDED
#define SERVERTHREAD_H_INCLUDED

#include "requestQueue.h"

typedef struct ServerThread ServerThread;

ServerThread* newServerThread(RequestQueue *queue, char *name, long seed);
void serverThreadRun(ServerThread *server);

#endif // SERVERTHREAD_H_INCLUDED
