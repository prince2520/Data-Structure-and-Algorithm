#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;

	node(int d){
		data = d;
		right = NULL;
		left = NULL;
	}
};

node* buildTree(){
	int d;
	cin >> d;

	if(d == -1){
		return NULL;
	}

	node* root = new node(d);

	root->left = buildTree();
	root->right = buildTree();

	return root; 
}

node* lca(node* root, int a, int b){
	// Base case 
	if(root == NULL){
		return NULL;
	}

	if(root->data == a or root->data == b){
		return root;
	}

	// Rec case 

	node* leftAns = lca(root->left, a, b);
	node* rightAns = lca(root->right, a, b);

	if(leftAns != NULL and rightAns != NULL){
		return root;
	}

	if(leftAns!=NULL){
		return leftAns;
	}

	return rightAns;
}



int main(){

	node* root = buildTree();

	cout << lca(root, 6, 7)->data << endl; 
	

	return 0;
}
