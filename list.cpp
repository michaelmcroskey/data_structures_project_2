// list.cpp

#include "lsort.h"

#include <memory>

List::List(int value = 0) {
	head = NULL;
}

List::~List() {
	
}

void List::push_front(const std::string &s) {
	Node* newNode = new Node;
	newNode->next = next;
	next = newNode;
	newNode->string = stoi(s);
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
