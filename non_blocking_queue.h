//
// Created by Dan Elias on 19/07/2025.
//
#ifndef NON_BLOCKING_QUEUE_H
#define NON_BLOCKING_QUEUE_H

#include "linked_list.h"
#include "pthread.h"

typedef struct NonBlockingQueue {
    LinkedListT* Queue;
    pthread_mutex_t NonBlockingMutex;
} NonBlockingQueueT;

void non_blocking_queue_init(NonBlockingQueueT* queue);
void non_blocking_queue_destroy(NonBlockingQueueT* queue);
void non_blocking_queue_push(NonBlockingQueueT* queue, void* data);
void* non_blocking_queue_pop(NonBlockingQueueT* queue);
int non_blocking_queue_empty(NonBlockingQueueT* queue);
int non_blocking_queue_length(NonBlockingQueueT* queue);


#endif //NON_BLOCKING_QUEUE_H
