// merge.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations

void merge_sort(List &l, bool numeric) {
    if( numeric )
        l.head = msort(l.head, node_number_compare );
    else
        l.head = msort(l.head, node_string_compare );
}

Node *msort(Node *head, CompareFunction compare) {
    // stop at one element
    if(!head->next)
        return head;
    
    Node *left = NULL;
    Node *right = NULL;
    
    // split list into two
    split(head, left, right);
    
    //recursion on both lists
    left = msort(left, compare);
    right = msort(right, compare);
    
    return merge(left, right, compare);
}

void split(Node *head, Node *&left, Node *&right) {
    left = head;            // left starts at first element
    right = head->next;     // right starts at second
    Node *trailRight = head;// element before split
    Node *current = right;
    
    while(current){
        current = current->next;
        
        // try to move second time, also moving right
        if(current){
            current = current->next;
            trailRight = right;
            right = right->next;
        }
    }
    
    trailRight->next = NULL;    // cut end of left list
}

Node *merge(Node *left, Node *right, CompareFunction compare) {
    Node *head;
    
    // set head node to smaller first element
    if( compare( left, right ) ) {
        head = right;
        right = right->right;
    }
    else {
        head = left;
        left = left->left;
    }
        
    Node *current = head;
    
    // loop while there are unprocessed elements
    while(left || right){
        // must compare if neither list is empty
        if(left && right) {
            if( compare( left, right ) ) {
                current->next = right;
                right = right->next;
            }
            else {
                current->next = left;
                left = left->next;
            }
        }
        else {      // one list is empty
            if(left)
                current->next = left;
            else
                current->next = right;
                
            break;  // just connect list and stop adding
        }
            
        current = current->next;
    }
    
    return head;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
