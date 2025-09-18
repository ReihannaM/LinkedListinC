// list/list.c
// Implementation of linked list
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Allocate a new list (heap-allocated)
list_t *list_alloc() {
    list_t *l = (list_t *)malloc(sizeof(list_t));
    l->head = NULL;
    return l;
}

// Free all nodes and the list itself
void list_free(list_t *l) {
    node_t *curr = l->head;
    while (curr != NULL) {
        node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(l);
}

// Print the list elements
void list_print(list_t *l) {
    node_t *curr = l->head;
    printf("[");
    while (curr != NULL) {
        printf("%d", curr->value);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf("]\n");
}

// Convert list to a string (caller must free)
char* listToString(list_t *l) {
    static char buffer[1024]; // simple static buffer for now
    buffer[0] = '\0';
    node_t *curr = l->head;
    while (curr != NULL) {
        char temp[32];
        sprintf(temp, "%d ", curr->value);
        strcat(buffer, temp);
        curr = curr->next;
    }
    return buffer;
}

// Helper to get a new node (heap allocated)
node_t * getNode(elem value) {
    node_t *n = (node_t *)malloc(sizeof(node_t));
    n->value = value;
    n->next = NULL;
    return n;
}

// Return length of the list
int list_length(list_t *l) {
    int count = 0;
    node_t *curr = l->head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

// Add value to back
void list_add_to_back(list_t *l, elem value) {
    node_t *n = getNode(value);
    if (l->head == NULL) {
        l->head = n;
        return;
    }
    node_t *curr = l->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = n;
}

// Add value to front
void list_add_to_front(list_t *l, elem value) {
    node_t *n = getNode(value);
    n->next = l->head;
    l->head = n;
}

// Add value at specific index (1-based index)
void list_add_at_index(list_t *l, elem value, int index) {
    if (index <= 1) {
        list_add_to_front(l, value);
        return;
    }
    int pos = 1;
    node_t *curr = l->head;
    while (curr != NULL && pos < index - 1) {
        curr = curr->next;
        pos++;
    }
    if (curr == NULL) {
        list_add_to_back(l, value);
        return;
    }
    node_t *n = getNode(value);
    n->next = curr->next;
    curr->next = n;
}

// Remove from back
elem list_remove_from_back(list_t *l) {
    if (l->head == NULL) return -1;
    if (l->head->next == NULL) {
        elem val = l->head->value;
        free(l->head);
        l->head = NULL;
        return val;
    }
    node_t *curr = l->head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    elem val = curr->next->value;
    free(curr->next);
    curr->next = NULL;
    return val;
}

// Remove from front
elem list_remove_from_front(list_t *l) {
    if (l->head == NULL) return -1;
    node_t *temp = l->head;
    elem val = temp->value;
    l->head = l->head->next;
    free(temp);
    return val;
}

// Remove at index (1-based index)
elem list_remove_at_index(list_t *l, int index) {
    if (l->head == NULL) return -1;
    if (index <= 1) {
        return list_remove_from_front(l);
    }
    node_t *curr = l->head;
    int pos = 1;
    while (curr->next != NULL && pos < index - 1) {
        curr = curr->next;
        pos++;
    }
    if (curr->next == NULL) return -1;
    node_t *temp = curr->next;
    elem val = temp->value;
    curr->next = temp->next;
    free(temp);
    return val;
}

// Check if element exists
bool list_is_in(list_t *l, elem value) {
    node_t *curr = l->head;
    while (curr != NULL) {
        if (curr->value == value) return true;
        curr = curr->next;
    }
    return false;
}

// Get element at index (1-based index)
elem list_get_elem_at(list_t *l, int index) {
    int pos = 1;
    node_t *curr = l->head;
    while (curr != NULL) {
        if (pos == index) return curr->value;
        curr = curr->next;
        pos++;
    }
    return -1; // not found
}

// Get index of element (1-based index)
int list_get_index_of(list_t *l, elem value) {
    int pos = 1;
    node_t *curr = l->head;
    while (curr != NULL) {
        if (curr->value == value) return pos;
        curr = curr->next;
        pos++;
    }
    return -1;
}
