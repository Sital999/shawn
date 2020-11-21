#include <bits/stdc++.h> 
#include"merge_sorting.h"
using namespace std; 
  
/* Link list node 
struct LNode  
{  
    public: 
    int data;  
    LNode* next;  
};  
  */

/* A Binary Tree node */
struct TNode  
{   
    node* data;  
    TNode* left;  
    TNode* right;  
};  
  
TNode* newNode(node* data);  
int countLNodes(node *head);  
TNode* sortedListToBSTRecur(node **head_ref, int n);  
struct node* bst_search(struct TNode* root, int key); 
  
/* This function counts the number of  
nodes in Linked List and then calls  
sortedListToBSTRecur() to construct BST */
TNode* sortedListToBST(node *head)  
{  
    /*Count the number of nodes in Linked List */
    int n = countLNodes(head);  
  
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);  
}  
  
/* The main function that constructs  
balanced BST and returns root of it.  
head_ref --> Pointer to pointer to  
head node of linked list n --> No. 
of nodes in Linked List */
TNode* sortedListToBSTRecur(node **head_ref, int n)  
{  
    /* Base Case */
    if (n <= 0)  
        return NULL;  
  
    /* Recursively construct the left subtree */
    TNode *left = sortedListToBSTRecur(head_ref, n/2);  
  
    /* Allocate memory for root, and  
    link the above constructed left  
    subtree with root */
    TNode *root = newNode((*head_ref));  
    root->left = left;  
  
    /* Change head pointer of Linked List 
    for parent recursive calls */
    *head_ref = (*head_ref)->next;  
  
    /* Recursively construct the right  
        subtree and link it with root  
        The number of nodes in right subtree 
        is total nodes - nodes in  
        left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);  
  
    return root;  
}  
  
  
  
/* UTILITY FUNCTIONS */
  
/* A utility function that returns  
count of nodes in a given Linked List */
int countLNodes(node *head)  
{  
    int count = 0;  
    node *temp = head;  
    while(temp)  
    {  
        temp = temp->next;  
        count++;  
    }  
    return count;  
}  
  
/* Function to insert a node  
at the beginging of the linked list 
void push(node** head_ref, int new_data)  
{  
    
    node* new_node = new node(); 
  
    new_node->data = new_data;  
  
    new_node->next = (*head_ref);  
  
    (*head_ref) = new_node;  
}  
*/
  
/* Function to print nodes in a given linked list 
void printList(node *node)  
{  
    while(node!=NULL)  
    {  
        cout << node->data << " ";  
        node = node->next;  
    }  
}  
*/
  
/* Helper function that allocates a new node with the  
given data and NULL left and right pointers. */
TNode* newNode(node* data)  
{  
    TNode* newnode = new TNode(); 
    newnode->data = data;  
    newnode->left = NULL;  
    newnode->right = NULL;  
  
    return newnode;  
}  





struct node* bst_search(struct TNode* root, int key) 
{ 
    node *base = root->data;

    if(root == NULL ) return 0;
  
    // Base Cases: root is null or key is present at root 
    if (base->ID == key) 
       return base; 
     
    // Key is greater than root's key 
    if (base->ID < key) 
       return bst_search(root->right, key); 
    else {
        // Key is smaller than root's key 
        return bst_search(root->left, key); 
    }
    
}
    

 


 
/* A utility function to  
print preorder traversal of BST 
void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
}  
  */