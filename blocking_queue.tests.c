//
// Created by Dan Elias on 08/01/2026.
//

#include "blocking_queue.h"
#include <stdio.h>

void create() {
  BlockingQueueT q;
  printf("Test creation\n");
  init_BlockingQueue(&q);
  assert(&q);
  destroy_BlockingQueue(&q);
  printf("test passsed\n");
}

void empty() {
  BlockingQueueT q;
  printf("Test empty\n");
  init_BlockingQueue(&q);
  assert(&q);
  assert(get_empty_BlockingQueue(&q) == 1);
  destroy_BlockingQueue(&q);
  printf("test passed\n");
}

void push() {
  BlockingQueueT q;
  printf("Test push\n");
  init_BlockingQueue(&q);
  assert(&q);
  for (int i = 0; i < 10; i++) {
    push_BlockingQueue(&q, (void*)i);
  }
  for (int i = 0; i < 10; i++) {
    assert(q.Queue->head->data == (void*)i);
    q.Queue->head = q.Queue->head->next;
  }
  printf("test passed\n");
  destroy_BlockingQueue(&q);
}

void pop() {
  BlockingQueueT q;
  printf("Test pop\n");
  init_BlockingQueue(&q);
  assert(&q);
  for (int i = 0; i < 10; i++) {
    push_BlockingQueue(&q, (void*)i);
  }
  void* a = 0;
  for (int i = 0; i < 10; i++) {
    assert(pop_BlockingQueue(&q, a) == (void*)i);
  }
  printf("test passed\n");
  destroy_BlockingQueue(&q);
}

void queue_length() {
  BlockingQueueT q;
  printf("Test queue_length\n");
  init_BlockingQueue(&q);
  assert(&q);
  void* a = 0;
  for (int i = 0; i < 10; i++) {
    push_BlockingQueue(&q, (void*)i);
  }
  assert(get_length_BlockingQueue(&q) == 10);
  for (int i = 0; i < 5; i++)
    pop_BlockingQueue(&q, a);
  assert(get_length_BlockingQueue(&q) == 5);
  printf("test passed\n");
  destroy_BlockingQueue(&q);
}

int main() {
  create();
  empty();
  push();
  pop();
  queue_length();
  return 0;
}