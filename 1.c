#include <stdio.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
};

void printPreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	printf("%d ", node->data); 
	printPreorder(node->left); 
	printPreorder(node->right); 
}

void main()
{
	struct node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(28);
	root->left->right = newNode(31);
	root->right->left=newNode(40);
	root->right->right=newNode(50);
	root->right->right->left=newNode(32);
	root->right->right->right=newNode(41);
	
	/* The Structure of this Binary Tree is going to be: 
	
						10	
												
				20				30
			
			28		31		40		     50
			
								     32		 41

	*/
	
	printPreorder(root);
}

