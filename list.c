#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t *current = head;
        list_t *previous = NULL;

	int not_inserted;
	not_inserted = 1;
	while(current->next != NULL){
		if(new_element->index < current->index){
			new_element->next = current;
			if(previous != NULL){
                              previous->next = new_element;
                        }
			not_inserted = 0;
                        break;
		}
                 previous = current;
		current = current->next;
	}
	if(not_inserted == 1){
		current->next = new_element;
		new_element->next = NULL;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
	list_t *tracker = head;
	list_t *previous = NULL;
	list_t *next_element;
	while(tracker != NULL){
		next_element = tracker->next;
		tracker->next = previous;
		previous = tracker;
		tracker = next_element;
	}
        head = previous;

	return head;
}

