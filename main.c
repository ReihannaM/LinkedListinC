#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("===== Linked List Tests =====\n\n");

    list_t *myList = list_alloc();

    printf("Basic Test: Add to front and back\n");
    list_add_to_front(myList, 10);
    list_add_to_back(myList, 20);
    list_add_to_back(myList, 30);
    list_print(myList); // Expected: 10 -> 20 -> 30

    printf("\nLength: %d (Expected 3)\n", list_length(myList));

    printf("\nGet elem at index 2: %d (Expected 20)\n", list_get_elem_at(myList, 2));
    printf("Index of 30: %d (Expected 3)\n", list_get_index_of(myList, 30));

    
    printf("\nHarder Test: Add at index\n");
    list_add_at_index(myList, 15, 2); // Insert 15 between 10 and 20
    list_print(myList); // Expected: 10 -> 15 -> 20 -> 30

    printf("\nRemove from front: %d (Expected 10)\n", list_remove_from_front(myList));
    list_print(myList);

    printf("\nRemove from back: %d (Expected 30)\n", list_remove_from_back(myList));
    list_print(myList);

    printf("\nRemove at index 2: %d (Expected 20)\n", list_remove_at_index(myList, 2));
    list_print(myList);

    // Edge Cases 
    printf("\nEdge Case: Remove from empty list\n");
    list_remove_from_front(myList); // remove last element (15)
    list_remove_from_front(myList); // list is empty now
    list_print(myList);

    printf("\nIs 100 in list? %s\n", list_is_in(myList, 100) ? "Yes" : "No");

    // Stress Test 
    printf("\nStress Test: Insert 100 nodes\n");
    for (int i = 1; i <= 100; i++) {
        list_add_to_back(myList, i);
    }
    printf("Length after 100 inserts: %d (Expected 100)\n", list_length(myList));

    // Cleanup
    list_free(myList);
    printf("\nAll tests finished. Memory freed.\n");

    return 0;
}
