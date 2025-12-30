//
// Created by Dan Elias on 19/07/2025.
//

#include "non_blocking_queue.h"

void init_NonBlockingQueue(NonBlockingQueueT* queue) {
  queue->Queue = create_LinkedList();
  assert(queue->Queue != NULL);
  pthread_mutex_init(&(queue->NonBlockingMutex), NULL);
}

void destroy_NonBlockingQueue(NonBlockingQueueT* queue) {
  assert(queue);
  pthread_mutex_lock(&(queue->NonBlockingMutex));
  destroy_LinkedList(queue->Queue);
  pthread_mutex_unlock(&(queue->NonBlockingMutex));
  pthread_mutex_destroy(&(queue->NonBlockingMutex));

}
void push_NonBlockingQueue(NonBlockingQueueT* queue, void* data) {
  assert(queue);
  pthread_mutex_lock(&(queue->NonBlockingMutex));
  append_LinkedList(queue->Queue, data);
  pthread_mutex_unlock(&(queue->NonBlockingMutex));
}

void* pop_NonBlockingQueue(NonBlockingQueueT* queue) {
  void* data = NULL;
  pthread_mutex_lock(&(queue->NonBlockingMutex));
  data = pop_front_LinkedList(queue->Queue);
  pthread_mutex_unlock(&(queue->NonBlockingMutex));
  return data;
}

int get_empty_NonBlockingQueue(NonBlockingQueueT* queue) {
  return (get_length_LinkedList(queue->Queue) == 0);
}

int get_length_NonBlockingQueue(NonBlockingQueueT* queue) {
  return get_length_LinkedList(queue->Queue);
}