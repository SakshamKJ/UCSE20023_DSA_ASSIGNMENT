#include <iostream>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void inorder(Node *root){
    if(root!=NULL){
    	inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  
    
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->right->left=new Node(32);
	root->right->right->right=new Node(41);
	root->left->left=new Node(28);
	root->left->right=new Node(31);
	
	/* The Structure of this Binary Tree is going to be: 
	
						10	
												
				20				30
			
			28		31		40		     50
			
								     32		 41

	*/
	inorder(root);
}
