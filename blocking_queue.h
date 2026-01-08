//
// Created by Dan Elias on 19/07/2025.
//

#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include "linked_list.h"
#include "pthread.h"

typedef struct BlockingQueue {
  LinkedListT* Queue;
  pthread_mutex_t lock;
  pthread_cond_t not_empty;
} BlockingQueueT;

void init_BlockingQueue(BlockingQueueT* queue);
void destroy_BlockingQueue(BlockingQueueT* queue);
void push_BlockingQueue(BlockingQueueT* queue, void* data);
int pop_BlockingQueue(BlockingQueueT* queue, void** var);
int get_empty_BlockingQueue(BlockingQueueT* queue);
int get_length_BlockingQueue(BlockingQueueT* queue);
#endif //BLOCKING_QUEUE_H
