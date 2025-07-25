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

LinkedListT* create_LinkedList() {}
void destroy_LinkedList(LinkedListT* list) {}
void prepend_LinkedList(LinkedListT* list, int data) {}
void append_LinkedList(LinkedListT* list, int data) {}
int pop_front_LinkedList(LinkedListT* list) {}
int pop_back_LinkedList(LinkedListT* list) {}
int get_length_LinkedList(LinkedListT* list) {}