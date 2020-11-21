#include <bits/stdc++.h> 
using namespace std; 
  


/* function prototypes */


struct node
 {
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct    node* next;
};
struct node *head=NULL;