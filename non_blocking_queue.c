//
// Created by Dan Elias on 19/07/2025.
//

#include "non_blocking_queue.h"

void init_NonBlockingQueue(NonBlockingQueueT* queue) {
  queue->Queue = create_LinkedList();
  assert(queue->Queue != NULL);
  pthread_mutex_init(&(queue->lock), NULL);
}

void destroy_NonBlockingQueue(NonBlockingQueueT* queue) {
  assert(queue);
  pthread_mutex_lock(&(queue->lock));
  destroy_LinkedList(queue->Queue);
  pthread_mutex_unlock(&(queue->lock));
  pthread_mutex_destroy(&(queue->lock));

}
void push_NonBlockingQueue(NonBlockingQueueT* queue, void* data) {
  assert(queue);
  pthread_mutex_lock(&(queue->lock));
  append_LinkedList(queue->Queue, data);
  pthread_mutex_unlock(&(queue->lock));
}

int pop_NonBlockingQueue(NonBlockingQueueT* queue, void** var) {
  pthread_mutex_lock(&(queue->lock));
  int length = get_length_NonBlockingQueue(queue);
  int pop = 0;
  if (length > 0) {
    *var = pop_front_LinkedList(queue->Queue);
  } else {
    pop =  1;
  }
  pthread_mutex_unlock(&(queue->lock));
  return pop;
}

int get_empty_NonBlockingQueue(NonBlockingQueueT* queue) {
  pthread_mutex_lock(&(queue->lock));
  int length = get_length_NonBlockingQueue(queue);
  pthread_mutex_unlock(&(queue->lock));
  return length == 0;
}

int get_length_NonBlockingQueue(NonBlockingQueueT* queue) {
  return get_length_LinkedList(queue->Queue);
}