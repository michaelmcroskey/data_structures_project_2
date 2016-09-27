// qsort.cpp

#include "lsort.h"

#include <cstdlib>
#include <array>
#include <iostream>

void qsort_sort(List &l, bool numeric) {
	
	int size = l.size;
		
	struct Node *a[size+1];		// create array
	struct Node *p = l.head;		// current pointer at head
	
	int i = 0;	
	while(p != nullptr){			// copy element-by-element
		a[i++] = p;
		p = p->next;
	}
	
	std::qsort(a, size, sizeof(struct Node *), void_number_compare);
	
	// update the links between the struct Nodes
	a[size] = nullptr;		// last element is null
	struct Node *curr;		// current pointer

	for (int j=0; j < size; j++){
		curr = a[j];
		curr->next = a[j+1];
		curr = curr->next;
	}
	
	// set the head of struct List
	l.head = a[0];
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
