// list.cpp

#include "lsort.h"

#include <memory>

List::List() {
	head = nullptr;
	size = 0;
}

List::~List() {
	Node* current = head;
	while(current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	size = 0;
}

void List::push_front(const std::string &s) {
	Node* newNode = new Node;
	newNode->next = head;
	head = newNode;
	newNode->number = stoi(s);
	size += 1;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
