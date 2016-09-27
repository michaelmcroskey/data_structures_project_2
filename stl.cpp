// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>

void stl_sort(List &l, bool numeric) {
	
	int size = l.size;
	
	struct Node *a[size+1];		// create array
	struct Node *p = l.head;		// current pointer at head
	
	int i = 0;	
	while(p != nullptr){			// copy element-by-element
		a[i++] = p;
		p = p->next;
	}
	
	if (numeric){
		std::sort(a, a+size, node_number_compare);
	} else {
		std::sort(a, a+size, node_string_compare);
	}
	
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
