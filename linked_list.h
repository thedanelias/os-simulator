//
// Created by Dan Elias on 19/07/2025.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} nodeT;

typedef struct linkedList {
  nodeT* head;
  nodeT* tail;
} linkedListT;

linkedListT* create_linkedList();
void destroy_linkedList(linkedListT*);
void prepend_linkedList(linkedListT*, int);
void append_linkedList(linkedListT*, int);
void pop_front_linkedList(linkedListT*);
void pop_back_linkedList(linkedListT*);
int get_element_from_front_linkedList(linkedListT*, int);
int get_element_from_back_linkedList(linkedListT*, int);
int get_length_linkedList(linkedListT* list);


#endif //LINKED_LIST_H
