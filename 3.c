#include<stdio.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node *insert(struct node *root, int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp -> left = temp-> right = NULL;
	
	if(root == NULL){
		root = temp;
	}
	if(x < root-> data){
		root -> left = insert(root->left, x);
	}
	if(x > root->data){
		root -> right = insert(root->right, x);
	}
	return (root);
}

void Preorder(struct node* node)
{ 
	if (node == NULL) 
		return; 

	printf("%d ", node->data); 
	Preorder(node->left); 
	Preorder(node->right); 
}


void main(){
	int tree[] = {43,21,20,1,3,24,5,6,89,72};
	int i;
	struct node *root = NULL;
	int n;
	n = sizeof(tree)/sizeof(tree[0]);
	for (i=0; i <= n; i++){
		root = insert(root, tree[i]);
	}
	
	Preorder(root);
}
