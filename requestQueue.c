
#include <stdlib.h>

#include "requestQueue.h"

struct RequestList{
    Request *req;
    struct RequestList *next;
};

typedef struct RequestQueue{
    struct RequestList *first_node;
    struct RequestList *last_node;
} RequestQueue;

static pthread_mutex_t mutex;
static pthread_cond_t cond;

RequestQueue* 
newRequestQueue() 
{
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    
    RequestQueue *queue = malloc(sizeof(RequestQueue));
    queue->first_node = NULL;
    queue->last_node = NULL;
    
    return queue;
}

Request* 
getRequest(RequestQueue *queue) 
{
    pthread_mutex_lock(&mutex);

    while (queue->first_node == NULL) 
    {
        pthread_cond_wait(&cond, &mutex);
    }

    Request *req;
	req = queue->first_node->req;

    struct RequestList *temp = queue->first_node;
    queue->first_node = queue->first_node->next;
    
    if (queue->first_node == NULL)
        queue->last_node = NULL;
        
    free(temp);

    pthread_mutex_unlock(&mutex);

    return req;
}

void 
putRequest(Request *req, RequestQueue *queue) 
{
    pthread_mutex_lock(&mutex);
    
    struct RequestList *new_request;
    new_request = malloc(sizeof(struct RequestList));
    new_request->req = req;
    new_request->next = NULL;

    if (queue->last_node == NULL)
    {
        queue->first_node = queue->last_node = new_request;
    } 
    else {
        queue->last_node->next = new_request;
        queue->last_node = new_request;
    }

    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}

