#include<stdio.h> 
#include<stdlib.h> 
#include"Header.h"

 
 
int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 


int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 


struct Node* newNode(int key) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
	return(node); 
} 


struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	// Return new root 
	return x; 
} 


struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	
	y->left = x; 
	x->right = T2; 


	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 


	return y; 
} 


int getBalance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

 
struct Node* insert(struct Node* node, int key) 
{ 

	if (node == NULL) 
		return(newNode(key)); 

	if (key <= node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else  
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 


	int balance = getBalance(node);  

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 


	return node; 
} 

 
void preOrder(struct Node *root) 
{ 
	
	if(root != NULL) 
	{ 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	}
 
} 

void postOrder(struct Node *root) 
{ 
     if (root != NULL)  
     {
     	postOrder(root->left); 
		postOrder(root->right); 
  		printf("%d ", root->key); 
  	}
}

void inOrder(struct Node *root) 
{ 
    if (root != NULL)  
    {
     	inOrder(root->left); 
		printf("%d ", root->key);
		inOrder(root->right); 
  	}	 
}

void Balancefactors(struct Node *root)
{
	if(root != NULL) 
	{ 
		int a=root->key;
		int b=getBalance(root);
		printf("\nKey:%d\tBalancefactor:%d", a,b); 
		Balancefactors(root->left); 
		Balancefactors(root->right); 
	} 
}

int search(struct Node *node,int n)
{
	struct Node *current = node;

	
	while(current->key != n)
	{
		if(current != NULL) 
		{
        	//printf("%d ",current->key);
			
        
        	if(current->key > n)
            	current = current->left;
           
         	else                
            	current = current->right;
        
        if(current == NULL)
            return 0;

         }
    }	
    if(current->key==n){
    	//printf("1");
    	return 1;		
    } 
   return 0;
}

/*int deletenode(struct Node *node,int n)
{
	struct Node *prev,*lchild,*rchild;
	struct Node *curr=node;
	lchild=curr->left;
	rchild=curr->right
	if(curr->key=n)
	{
		if(lchild==NULL && rchild==NULL)
		{
			free(curr);
			curr=NULL;
			return 1;
		}
		if(lchild==NULL)
		{
			curr=rchild;
			return 1;
		}
		curr=lchild;
		return 1;

	}
	else
	{
		while(curr->key!=n)
		{
			prev=curr;
			if(n < curr->key)
			{
				curr=curr->left;
				lchild=curr->left;
				rchild=curr->right;
			}
			else
			{
				curr=curr->right;
				lchild=curr->left;
				rchild=curr->right;
			}
		}
		if(rchild==NULL)
		{
			if(prev->left==curr)
				prev->left=curr->left;
			else
				prev->right=curr->left;
			if(curr->left!=NULL)

		}
	}


}*/





struct Node* deleteNode(struct Node* root, int key) 
{ 
    
  
    if (root == NULL) 
        return root; 
  
   
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
   
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
  	else if( (root->left == NULL) &&(root->right == NULL) )
  	{
		root=NULL;
	}    
    else
    { 
       
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct Node *temp = root->left ? root->left : 
                                             root->right; 
  
       
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
             *root = *temp; 
            free(temp); 
        } 
        else
        { 
           
            struct Node* temp = minValueNode(root->right); 
  
            
            root->key = temp->key; 
  
           
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
  
   
    if (root == NULL) 
      return root; 

    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
} 


struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 