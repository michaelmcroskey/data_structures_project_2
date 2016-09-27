// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    
    if( numeric )
        l.head = qsort( l.head, node_number_compare );
    else
        l.head = qsort( l.head, node_string_compare );
}

Node *qsort(Node *head, CompareFunction compare) {
    // stop if less than two elements
    if( !head || !head->next )
        return head;
        
    Node *left = NULL;
    Node *right = NULL;
    
    // split list
    partition( head, head, left, right, compare );
    
    // recursion on both lists
    left  = qsort(left, compare);
    right = qsort(right, compare);
    
    return concatenate(left, right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    Node *current = head;
    Node *next;
    
    // move through original list
    while(current) {
        next = current->next;
       
       // move current node to head of a side list
        if( /*compare*/ ) {
            current->next = left;
            left = current;
        }
        else {
            current->next = right;
            right = current;
        }
        
        current = next;
    }
}

Node *concatenate(Node *left, Node *right) {
    // skip empty lists
    if( !left )
        return right;
    if( !right )
        return left;
    
    Node *current = left;
    while( current->next )        // Find last element of left
        current = current->next;
        
    current->next = right;        // Connect to right 
    
    return left;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
