// node.cpp

#include "lsort.h"

#include <iostream>
#include <string>

bool node_number_compare(const Node *a, const Node *b) {
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {	
	return a->string < b->string;
}

int void_number_compare(const void *a, const void *b) {
	const Node* aNode = *(const Node**) a;
	const Node* bNode = *(const Node**) b;
	
	if(aNode->number < bNode->number)
	    return -1;
	if(aNode->number > bNode->number)
	    return 1;
	return 0;
}

int void_string_compare(const void *a, const void *b) {
	const Node* aNode = *(const Node**) a;
	const Node* bNode = *(const Node**) b;
	
	if(aNode->string < bNode->string)
	    return -1;
	if(aNode->string > bNode->string)
	    return 1;
	return 0;
}

void dump_node(Node *n) {
	while(n != nullptr){
		std::cout << n->string << " " << n->number << std::endl;
		n = n->next;
	}
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
