//
// Created by Dan Elias on 20/07/2025.
//

#include "linked_list.h"
#include <stdio.h>

void test_empty_list() {
  printf("Testing empty list\n");
  LinkedListT* list = create_LinkedList();
  assert(list->head->data == -1);
  destroy_LinkedList(list);
  assert(!list);
  printf("Test successful\n");
}

void test_get_length() {
  printf("Testing get length\n");
  LinkedListT* list = create_LinkedList();
  list->head->data = 10;
  assert(get_length_LinkedList(list) == 1);
  append_LinkedList(list, 10);
  assert(get_length_LinkedList(list) == 2);
  destroy_LinkedList(list);
  printf("Test successful\n");
}

void test_list_prepend() {
  printf("Testing prepend list\n");
  LinkedListT* list = create_LinkedList();
  prepend_LinkedList(list, 10);
  assert(list->head->data == 10);
  prepend_LinkedList(list, 20);
  assert(list->head->data == 20);
  assert(get_length_LinkedList(list) == 2);
  destroy_LinkedList(list);
  printf("Test successful\n");
}

void test_list_append() {
  printf("Testing append\n");
  LinkedListT* list = create_LinkedList();
  append_LinkedList(list, 10);
  assert(list->tail->data == 10);
  append_LinkedList(list, 20);
  assert(list->tail->data == 20);
  assert(get_length_LinkedList(list) == 2);
  destroy_LinkedList(list);
  printf("Test successful\n");
}

void test_pop_front() {
  printf("Testing pop_front list\n");
  LinkedListT* list = create_LinkedList();
  append_LinkedList(list, 10);
  append_LinkedList(list, 20);
  append_LinkedList(list, 30);
  int num = pop_front_LinkedList(list);
  assert(num == 10);
  num = pop_front_LinkedList(list);
  assert(num == 20);
  assert(get_length_LinkedList(list) == 1);
  destroy_LinkedList(list);
  printf("Test successful\n");
}

void test_pop_back() {
  printf("Testing pop_back list\n");
  LinkedListT* list = create_LinkedList();
  append_LinkedList(list, 10);
  append_LinkedList(list, 20);
  append_LinkedList(list, 30);
  int num = pop_back_LinkedList(list);
  assert(num == 30);
  assert(get_length_LinkedList(list) == 2);
  num = pop_back_LinkedList(list);
  assert(num == 20);
  destroy_LinkedList(list);
  printf("Test successful\n");
}

int main(void) {
  test_empty_list();
  test_get_length();
  test_list_prepend();
  test_list_append();
  test_pop_front();
  test_pop_back();
  return 0;
}