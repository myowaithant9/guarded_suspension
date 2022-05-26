#ifndef CLIENTTHREAD_H_INCLUDED
#define CLIENTTHREAD_H_INCLUDED

#include "requestQueue.h"

typedef struct ClientThread ClientThread;

ClientThread* newClientThread(RequestQueue *queue, char *name, long seed);
void clientThreadRun(ClientThread *client);

#endif // CLIENTTHREAD_H_INCLUDED
