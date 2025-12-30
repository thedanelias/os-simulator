//
// Created by Dan Elias on 30/12/2025.
//

#include "non_blocking_queue.h"
#include <stdio.h>
#include <assert.h>

void queue_creation() {
  NonBlockingQueueT q;
  printf("Testing creation\n");
  init_NonBlockingQueue(&q);
  assert(&q);
  printf("Test passed, queue created\n");
  destroy_NonBlockingQueue(&q);
}

void queue_push() {
  NonBlockingQueueT q;
  printf("Testing push\n");
  init_NonBlockingQueue(&q);
  assert(&q);
  for (int i = 10; i < 40; i += 10) {
    push_NonBlockingQueue(&q, (void*)i);
  }
  for (int i = 10; i < 40; i += 10) {
    assert(q.Queue->head->data == (void*) i);
    q.Queue->head = q.Queue->head->next;
  }
  printf("Test passed\n");
  destroy_NonBlockingQueue(&q);
}

void queue_empty() {
  NonBlockingQueueT q;
  printf("Testing emptiness\n");
  init_NonBlockingQueue(&q);
  assert(&q);
  assert(get_empty_NonBlockingQueue);
  printf("Test passed, queue is empty\n");
  destroy_NonBlockingQueue(&q);
}


void queue_pop() {
  NonBlockingQueueT q;
  printf("Testing pop\n");
  init_NonBlockingQueue(&q);
  assert(&q);
  for (int i = 10; i < 40; i += 10) {
    push_NonBlockingQueue(&q, (void*)i);
  }
  pop_NonBlockingQueue(&q);
  pop_NonBlockingQueue(&q);
  assert(q.Queue->head->data == (void*) 30);
  printf("Test passed\n");
  destroy_NonBlockingQueue(&q);
}

void queue_length() {
  NonBlockingQueueT q;
  printf("Testing length\n");
  init_NonBlockingQueue(&q);
  assert(&q);
  for (int i = 10; i < 40; i += 10) {
    push_NonBlockingQueue(&q, (void*)i);
  }
  assert(get_length_NonBlockingQueue(&q) == 3);
  pop_NonBlockingQueue(&q);
  pop_NonBlockingQueue(&q);
  assert(get_length_NonBlockingQueue(&q) == 1);
  printf("Test passed\n");
  destroy_NonBlockingQueue(&q);
}

int main() {
  queue_creation();
  queue_empty();
  queue_push();
  queue_pop();
  queue_length();
  printf("All tests passed\n");
  return 0;
}
