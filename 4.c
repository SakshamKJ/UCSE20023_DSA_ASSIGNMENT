#include <stdio.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}


struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}


struct node* minValueNode(struct node* node)
{
	struct node* curr = node;
	while (curr && curr->left != NULL)
		curr = curr->left;
	return curr;
}


struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
int main()
{
	struct node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 12);
	root = insert(root, 18);
	root = insert(root, 20);
	root = insert(root, 80);

	printf("Inorder traversal of the given tree: ");
	inorder(root);

	root = deleteNode(root, 18);
	printf("\nInorder traversal of the tree after deleting 18: ");
	inorder(root);

	
	root = deleteNode(root, 5);
	printf("\nInorder traversal of the tree after deleting 5: ");
	inorder(root);

	root = deleteNode(root, 10);
	printf("\nInorder traversal of the tree after deleting 10: ");
	inorder(root);

	return 0;
}

