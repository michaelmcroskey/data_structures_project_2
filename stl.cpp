// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

void stl_sort(List &l, bool numeric) {
	
	int size = l.size;
	
	std::vector<struct Node *> a;		// create array
    a.reserve(size+1);
	struct Node *p = l.head;		// current pointer at head
	
	while(p != nullptr)			// copy element-by-element
    {
		a.push_back(p);
		p = p->next;
	}

	if (numeric){
		std::sort(&a[0], &a[0]+size, node_number_compare);
	} else {
		std::sort(&a[0], &a[0]+size, node_string_compare);
	}
	
	// update the links between the struct Nodes
	a.push_back(nullptr);		// last element is null
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
