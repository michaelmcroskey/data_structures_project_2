// node.cpp

#include "lsort.h"

#include <iostream>

bool node_number_compare(const Node *a, const Node *b) {
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {	
	return std::stoi(a->string) > std::stoi(b->string);
}

int void_number_compare(const void *a, const void *b) {
	const int* a_num = (const int*) a;
	const int* b_num = (const int*) b;
	
	return (*a_num > *b_num) ? 0 : 1;
}

// realized we're not comparing length and need to typecast
// but can't figure out how to do that with const void *
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
