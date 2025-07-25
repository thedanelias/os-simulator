//
// Created by Dan Elias on 19/07/2025.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <assert.h>

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} nodeT;

typedef struct LinkedList {
  nodeT* head;
  nodeT* tail;
} LinkedListT;

LinkedListT* create_LinkedList();
void destroy_LinkedList(LinkedListT* list);
void prepend_LinkedList(LinkedListT* list, int data);
void append_LinkedList(LinkedListT* list, int data);
int pop_front_LinkedList(LinkedListT* list);
int pop_back_LinkedList(LinkedListT* list);
int get_length_LinkedList(LinkedListT* list);


#endif //LINKED_LIST_H
