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

	node* root = new node(d);

	int no_of_child = 0;
	cin >> no_of_child;

	if(no_of_child == 0){
		return root;
	}else if(no_of_child == 1){
		root->left = buildTree();
	}else{
		root->left = buildTree();
		root->right = buildTree();
	}

	return root;
}

int sumATKthLvl(node* root, int lvl, int k){
	// Base case
	if(root == NULL){
		return 0;
	}

	if(lvl==k){
		return root->data;
	}

	// Rec case
	int leftAns = sumATKthLvl(root->left, lvl+1, k);
	int rightAns = sumATKthLvl(root->right, lvl+1, k);

	return (leftAns + rightAns);
}

int main(){
	node* root = buildTree();

	int k;
	cin>> k;

	cout << sumATKthLvl(root, 0, k) << endl;	

	return 0;
}