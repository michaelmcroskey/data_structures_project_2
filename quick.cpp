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
    // stop at empty or sorted
    if(!head)
        return NULL;

    bool sorted = true;
    for( Node *temp=head;temp->next;temp=temp->next)
        if( compare(temp->next, temp) )
            sorted = false;
    if(sorted)
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

    right = current;            // put pivot in right list
    current = current->next;
    Node *rightEnd = right;     // track end of list
    rightEnd->next = NULL;
    
    // move through original list
    while(current) {
        next = current->next;
       
       // move current node to front of a side list
        if( compare( current, pivot ) ) {
            current->next = left;
            left = current;
        }
        else if( current->number==pivot->number ) {
            rightEnd->next = current;   //place pivots together
            current->next = NULL;
            rightEnd = current;
        }
        else {                      // place at front of right list
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
