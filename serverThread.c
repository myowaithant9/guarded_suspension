#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "serverThread.h"

typedef struct ServerThread
{
    char *name;
    RequestQueue *queue;
} ServerThread;

ServerThread* 
newServerThread(RequestQueue *queue, char *name, long seed)
{
    ServerThread *server = malloc(sizeof(ServerThread));
    
    server->name = name;
    server->queue = queue;
    srand(seed);

    return server;
}

static int 
getRandomInt(int min, int max)
{
    return rand() % (max - min) + min;
}

void 
serverThreadRun(ServerThread *server)
{
    int i;
    
    for (i = 0; i < 10000; i++)
    {
        Request *req;
        req = getRequest(server->queue);
        printf("%s handles %s \n", server->name, toString(req));
        
        usleep(getRandomInt(0, 1000) * 1000);
    }
    
}
