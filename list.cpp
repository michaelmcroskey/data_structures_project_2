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
	newNode->next = head;
	head = newNode;
	newNode->number = stoi(s);
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
