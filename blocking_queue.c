//
// Created by Dan Elias on 19/07/2025.
//

#include "blocking_queue.h"

void init_BlockingQueue(BlockingQueueT* queue) {
  queue->Queue = create_LinkedList();
  assert(queue->Queue != NULL);
  pthread_mutex_init(&(queue->lock), NULL);
  pthread_cond_init(&(queue->not_empty), NULL);
}

void destroy_BlockingQueue(BlockingQueueT* queue) {
  assert(queue != NULL);
  pthread_mutex_lock(&(queue->lock));
  destroy_LinkedList(queue->Queue);
  pthread_cond_destroy(&(queue->not_empty));
  pthread_mutex_unlock(&(queue->lock));
  pthread_mutex_destroy(&(queue->lock));
}

void push_BlockingQueue(BlockingQueueT* queue, void* data) {
  assert(queue != NULL);
  pthread_mutex_lock(&(queue->lock));
  append_LinkedList(queue->Queue, data);
  pthread_cond_signal(&(queue->not_empty));
  pthread_mutex_unlock(&(queue->lock));
}

int pop_BlockingQueue(BlockingQueueT* queue, void** var) {
  assert(queue != NULL);
  pthread_mutex_lock(&(queue->lock));
  int pop = 0;
  while (get_length_BlockingQueue(queue) == 0) {
     pthread_cond_wait(&(queue->not_empty), &(queue->lock));
  }
  *var = pop_front_LinkedList(queue->Queue);
  pthread_mutex_unlock(&(queue->lock));
  return pop;
}

int get_length_BlockingQueue(BlockingQueueT* queue) {
  // don't lock as only called by other functions that have already locked
  assert(queue != NULL);
  return get_length_LinkedList(queue->Queue);
}

int get_empty_BlockingQueue(BlockingQueueT* queue) {
  assert(queue != NULL);
  pthread_mutex_lock(&(queue->lock));
  int length = get_length_BlockingQueue(queue);
  pthread_mutex_unlock(&(queue->lock));
  return length == 0;
}