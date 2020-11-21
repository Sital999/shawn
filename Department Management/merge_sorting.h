#include <bits/stdc++.h> 
#include"Variable.h"
using namespace std; 
  
/* Link list node 
class node { 
public: 
    int data; 
    node* next; 
}; 
  */

/* function prototypes */



  

  void FrontBackSplit(node* source, 
                    node** frontRef, node** backRef) 
{ 
    node* fast; 
    node* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 


node* SortedMerge(node* a, node* b) 
{ 
    node* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->ID <= b->ID) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 


/* sorts the linked list by changing next pointers (not data) */
void MergeSort(node** headRef) 
{ 
    node* head = *headRef; 
    node* a; 
    node* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
  
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 
  
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
} 
  
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this  
function */

  
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,  
    and return the two lists using the reference parameters.  
    If the length is odd, the extra node should go in the front list.  
    Uses the fast/slow pointer strategy. */

  
/* Function to print nodes in a given linked list 
void printList(node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  */
/* Function to insert a node at the beginging of the linked list 
void push(node** head_ref, int new_data) 
{ 
    node* new_node = new node(); 
  
    new_node->data = new_data; 
  
 
    new_node->next = (*head_ref); 
  
   
    (*head_ref) = new_node; 
} 
*/