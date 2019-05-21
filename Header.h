#include<stdio.h> 
#include<stdlib.h>

struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 

// A utility function to get maximum of two integers 
int max(int a, int b);
int height(struct Node *N);
struct Node* newNode(int key);
struct Node *rightRotate(struct Node *y) ;
struct Node *leftRotate(struct Node *x) ;
int getBalance(struct Node *N);
struct Node* insert(struct Node* node, int key);
void preOrder(struct Node *root);
void postorder(struct Node *root);
void inOrder(struct Node *root) ;
void Balancefactors(struct Node *root);
int search(struct Node *node,int n);
struct Node* deleteNode(struct Node* root, int key);
struct Node * minValueNode(struct Node* node);