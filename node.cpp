// node.cpp

#include "lsort.h"

#include <iostream>

bool node_number_compare(const Node *a, const Node *b) {
	return a->number > b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
	int a_size = a->string.length();
	int b_size = b->string.length();
	
	return a_size > b_size;
}

int void_number_compare(const void *a, const void *b) {
	const int* a_num = (const int*) a;
	const int* b_num = (const int*) b;
	
	return (*a_num > *b_num) ? 0 : 1;
}

int void_string_compare(const void *a, const void *b) {
	const std::string* a_str = (const std::string*) a;
	const std::string* b_str = (const std::string*) b;
	
	return (a_str->length() > b_str->length()) ? 1 : 0;
}

void dump_node(Node *n) {
	while(n != nullptr){
		std::cout << n->string << " " << n->number << std::endl;
		n = n->next;
	}
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
