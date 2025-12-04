//
// Created by Dan Elias on 19/07/2025.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <assert.h>

typedef struct node {
  void* data;
  struct node *next;
  struct node *prev;
} nodeT;

typedef struct LinkedList {
  nodeT* head;
  nodeT* tail;
  int length;
} LinkedListT;

LinkedListT* create_LinkedList();
void destroy_LinkedList(LinkedListT* list);
void prepend_LinkedList(LinkedListT* list, void* data);
void append_LinkedList(LinkedListT* list, void* data);
void* pop_front_LinkedList(LinkedListT* list);
void* pop_back_LinkedList(LinkedListT* list);
int get_length_LinkedList(LinkedListT* list);


#endif //LINKED_LIST_H
