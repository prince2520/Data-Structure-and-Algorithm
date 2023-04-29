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

int count(node* root){
	// Base case 
	if(root == NULL){
		return 0;
	}

	// Rec case
	return count(root->left) + count(root->right) + 1;
}


int sum(node *root){
	// Base case
	if(root == NULL){
		return 0;
	} 

	// Rec case 
	return sum(root->left) + sum(root->right) + root->data;
}



int main(){

	node* root = buildTree();

	cout << count(root) << endl;

	cout << sum(root) << endl;

	return 0;
}