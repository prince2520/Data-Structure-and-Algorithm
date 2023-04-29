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

int height(node* root){
	// Base case 
	if(root == NULL){
		return 0;
	}

	int left = height(root->left);
	int right = height(root->right);

	return max(left, right) + 1;
}

int diameter(node* root){
	if( root == NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);

	int opt1 = h1 + h2;
	int opt2 = diameter(root->left);
	int opt3 = diameter(root->right); 

	return max(opt1, max(opt2, opt3));
}

int main(){

	node* root = buildTree();

	cout << diameter(root) << endl;

	return 0;
}