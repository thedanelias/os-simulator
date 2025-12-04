//
// Created by Dan Elias on 20/07/2025.
//

#include "linked_list.h"
#include <stdio.h>

void test_empty_list() {
    printf("Test empty list\n");
    LinkedListT* list = create_LinkedList();
    assert(list);
    destroy_LinkedList(list);
    printf("Test passed\n");
}

void test_push_front() {
    printf("Test push_front\n");
    LinkedListT* list = create_LinkedList();
    assert(list);
    prepend_LinkedList(list, (void*)10);
    prepend_LinkedList(list, (void*)20);
    prepend_LinkedList(list, (void*)30);
    assert((int)list->head->data == 30);
    assert((int)list->tail->data == 10);
    destroy_LinkedList(list);
    printf("Test passed\n");
}

void test_push_back() {
    printf("Test push_back\n");
    LinkedListT* list = create_LinkedList();
    assert(list);
    append_LinkedList(list, (void*)10);
    append_LinkedList(list, (void*)20);
    append_LinkedList(list, (void*)30);
    assert((int)list->head->data == 10);
    assert((int)list->tail->data == 30);
    destroy_LinkedList(list);
    printf("Test passed\n");
}

void test_pop_front() {
    printf("Test pop_front\n");
    LinkedListT* list = create_LinkedList();
    assert(list);
    prepend_LinkedList(list, (void*)10);
    prepend_LinkedList(list, (void*)20);
    prepend_LinkedList(list, (void*)30);
    assert((int)list->head->data == 30);
    pop_front_LinkedList(list);
    assert((int)list->head->data == 20);
    pop_front_LinkedList(list);
    assert((int)list->head->data == 10);
    pop_front_LinkedList(list);
    assert(list->head == NULL);
    destroy_LinkedList(list);
    printf("Test passed\n");
}

void test_pop_back() {
    printf("Test pop_back\n");
    LinkedListT* list = create_LinkedList();
    append_LinkedList(list, (void*)10);
    append_LinkedList(list, (void*)20);
    append_LinkedList(list, (void*)30);
    assert((int)list->tail->data == 30);
    pop_back_LinkedList(list);
    assert((int)list->tail->data == 20);
    pop_back_LinkedList(list);
    assert((int)list->tail->data == 10);
    pop_back_LinkedList(list);
    assert(list->tail == NULL);
    destroy_LinkedList(list);
    printf("Test passed\n");

}

int main(void) {
    test_empty_list();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
}