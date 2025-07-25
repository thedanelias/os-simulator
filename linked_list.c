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
