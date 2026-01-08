//
// Created by Dan Elias on 19/07/2025.
//

#include "Linked_list.h"
#include <stdlib.h>

struct node* create_node() {
    nodeT* node = (nodeT*)malloc(sizeof(nodeT));
    node->next = node->prev = node->data = NULL;
    return node;
}

void destroy_node(nodeT* node){
    assert(node);
    free(node);
}

LinkedListT* create_LinkedList() {
    LinkedListT* list = (LinkedListT*)malloc(sizeof(LinkedListT));
    assert(list);
    list->head = list->tail = NULL;
    return list;
}

void destroy_LinkedList(LinkedListT* list) {
    // make sure list is valid
    assert(list);

    nodeT* node = list->head;
    // loop through entire list
    for (int i = 0; i < list->length; i++) {
        node = node->next;
        destroy_node(list->head);
        list->head = node;
    }
    // destroy list structure at the end after loop
    free(list);
}

void prepend_LinkedList(LinkedListT* list, void* data) {
    assert(list);
    nodeT* node = create_node();
    node->data = data;
    if (list->length > 0) {
        node->next = list->head;
        node->prev = list->tail;
        list->head->prev = node;
        list->tail->next = node;
        list->head = node;
    } else {
        node->next = node;
        node->prev = node;
        list->head = node;
        list->tail = node;
    }
    list->length++;
}

void append_LinkedList(LinkedListT* list, void* data) {
    assert(list);
    nodeT* node = create_node();
    node->data = data;
    if (list->length > 0) {
        node->next = list->head;
        node->prev = list->tail;
        list->head->prev = node;
        list->tail->next = node;
        list->tail = node;
    } else {
        node->next = node;
        node->prev = node;
        list->head = node;
        list->tail = node;
    }
    list->length++;
}

void* pop_front_LinkedList(LinkedListT* list) {
    assert(list);
    nodeT* node = list->head->next;
    void* data = list->head->data;
    if (list->length == 1) {
        list->head = list->tail = NULL;
    } else if (list->length == 2) {
        destroy_node(list->head);
        list->head = list->tail = node;
    } else {
        destroy_node(list->head);
        node->prev = list->tail;
        list->head = node;
        list->tail->next = node;
    }
    list->length--;
    return data;
}

void* pop_back_LinkedList(LinkedListT* list) {
    assert(list);
    nodeT* node = list->tail->prev;
    void* data = node->data;
    if (list->length == 1) {
        destroy_node(list->tail);
        list->head = list->tail = NULL;
    } else if (list->length == 2) {
        destroy_node(list->tail);
        list->head = list->tail = node;
    } else {
        destroy_node(list->tail);
        node->next = list->head;
        list->tail = node;
        list->head->prev = node;
    }
    list->length--;
    return data;
}
int get_length_LinkedList(LinkedListT* list) {
    assert(list);
    return list->length;
}