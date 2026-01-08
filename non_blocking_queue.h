//
// Created by Dan Elias on 19/07/2025.
//
#ifndef NON_BLOCKING_QUEUE_H
#define NON_BLOCKING_QUEUE_H

#include "linked_list.h"
#include "pthread.h"

typedef struct NonBlockingQueue {
    LinkedListT* Queue;
    pthread_mutex_t lock;
} NonBlockingQueueT;

void init_NonBlockingQueue(NonBlockingQueueT* queue);
void destroy_NonBlockingQueue(NonBlockingQueueT* queue);
void push_NonBlockingQueue(NonBlockingQueueT* queue, void* data);
int pop_NonBlockingQueue(NonBlockingQueueT* queue, void** var);
int get_empty_NonBlockingQueue(NonBlockingQueueT* queue);
int get_length_NonBlockingQueue(NonBlockingQueueT* queue);


#endif //NON_BLOCKING_QUEUE_H
