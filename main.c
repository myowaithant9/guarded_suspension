#include "requestQueue.h"
#include "clientThread.h"
#include "serverThread.h"

int 
main(int argc, char** argv) 
{
    RequestQueue *queue = newRequestQueue();

    pthread_t t_client, t_server;

    ClientThread *client = newClientThread(queue, "Alice", 3141592L);
    ServerThread *server = newServerThread(queue, "Bobby", 6535897L);

    pthread_create(&t_client, NULL, (void *)clientThreadRun, (void *)client);
    pthread_create(&t_server, NULL, (void *)serverThreadRun, (void *)server);

    pthread_join(t_client, NULL);
    pthread_join(t_server, NULL);

    return 0;
}
