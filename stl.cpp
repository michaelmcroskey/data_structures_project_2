// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>

void stl_sort(List &l, bool numeric) {
	
	int size = l.size + 1;
	
	struct Node *a[size];		// create array
	struct Node *p = l.head;		// current pointer at head
	a[0] = p;					// first element is head pointer
	
	int i = 1;
	
	while(p != nullptr){			// copy element-by-element
		a[i++] = p;
		p = p->next;
	}
	
	std::sort(a+1, a+size, node_number_compare);
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
