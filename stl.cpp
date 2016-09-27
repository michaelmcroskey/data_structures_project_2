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
	
	std::sort(a, a+size, node_number_compare);
	
	// update the links between the struct Nodes to reflect the sorted order
	a[size] = nullptr;
	struct Node *curr;		// current pointer

	for (int j=0; j < size; j++){
		curr = a[j];
		curr->next = a[j+1];
		curr = curr->next;
	}
	
	// set the head of the struct List after you have set the links of all the struct Nodes
	l.head = a[0];
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
