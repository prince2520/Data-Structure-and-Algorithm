#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	int d;
	cin >> d;

	if(d == -1){
		return NULL;
	}

	node *root = new node(d);

	root->left = buildTree();
	root->right = buildTree();

	return root;
}

// Inorder
void printIn(node* root){
	if(root == NULL){
		return;
	}

	printIn(root->left);
	cout << root->data << " ";
	printIn(root->right);
}

// Postorder 
void printPost(node* root){
	if(root == NULL){
		return;
	}

	printPost(root->left);
	printPost(root->right);

    cout << root->data << " ";

}

int main(){

	node* root = buildTree();

	// Inorder
	printIn(root);
	cout << endl;

	// Post Order
	printPost(root);	

	return 0;
}