#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "clientThread.h"

typedef struct ClientThread
{
    char *name;
    RequestQueue *queue;
} ClientThread;

ClientThread* 
newClientThread(RequestQueue *queue, char *name, long seed)
{
    ClientThread *client = malloc(sizeof(ClientThread));
    
    client->name = name;
    client->queue = queue;
    srand(seed);

    return client;
}

static int 
getRandomInt(int min, int max)
{
    return rand() % (max - min) + min;
}

void 
clientThreadRun(ClientThread *client)
{
    int i;
    char msg[64];
    for (i = 0; i < 10000; i++)
    {
        sprintf(msg, "No. %d", i);
        
        Request *req;
        req = newRequest(msg);
        
        printf("%s requests %s\n", client->name, toString(req));
        putRequest(req, client->queue);

        usleep(getRandomInt(0, 1000) * 1000);
    }
}
