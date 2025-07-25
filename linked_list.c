//
// Created by Dan Elias on 19/07/2025.
//

#include "Linked_list.h"
#include <stdlib.h>

struct node* createNode(int data){
  nodeT* newNode = (nodeT*)malloc(sizeof(nodeT));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  assert(newNode);
  return newNode;
}

void destroyNode(nodeT* node){
  assert(node);
  free(node);
}

LinkedListT* create_LinkedList() {
  // create list
  LinkedListT* list = (LinkedListT*)malloc(sizeof(LinkedListT));
  assert(list);

  // create sentinel node - set to -1 as that value can't be used
  nodeT* newNode = createNode(-1);
  newNode->next = newNode;
  newNode->prev = newNode;
  assert(newNode);
  list->head = newNode;
  list->tail = newNode;
  return list;
}
void destroy_LinkedList(LinkedListT* list) {}
void prepend_LinkedList(LinkedListT* list, int data) {}
void append_LinkedList(LinkedListT* list, int data) {}
int pop_front_LinkedList(LinkedListT* list) {}
int pop_back_LinkedList(LinkedListT* list) {}
int get_length_LinkedList(LinkedListT* list) {}