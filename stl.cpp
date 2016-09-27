// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>

void stl_sort(List &l, bool numeric) {

	std::vector<int> v;
	struct Node *p = l.head;
	while(1){
		v.push_back(p->number);
		if (p->next == nullptr) break;
		p = p->next;
	}
	
	std::sort(v.begin(), v.end());
	
//	int array[l.size + 1];
//	struct Node *p = l.head;
//	array[0] = p->number;
//	
//	int i = 1;
//	
//	while(1){
//		array[i++] = p->number;
//		if (p->next == nullptr) break;
//		p = p->next;
//	}
//	
//	std::sort(std::begin(array), std::end(array));
	
//The first sorting mode is to use the std::sort method in the stl.cpp file. Because our struct List does not implement random access iterators, we will need to copy the struct Nodes in the struct List into another container such as an array. Once we have this copy, we can then call the std::sort function on this copy with the appropriate comparison function. Finally, we must update the links between the struct Nodes to reflect the sorted order.
//
//	Hint: You should store struct Node * in your copy array.
//
//	Hint: Make sure you set the head of the struct List after you have set the links of all the struct Nodes.
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
