#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		right = NULL;
		left = NULL;
	}
};


node* buildTree(){
	int d;
	cin >> d;

	node* root = new node(d);

	string l;
	cin >> l;

	if( l == "true"){
		root->left = buildTree();
	}

	string r;
	cin >> r;

	if( r == "true"){
		root->right = buildTree();
	}

	return root;
}

class HBPair{
public:
	int depth;
	bool balanced;
};

HBPair isBalancedTree(node*root){
	HBPair p;
	// Base case
	if(root == NULL){
		p.depth = 0;
		p.balanced = true;
		return p;
	}

	// Rec case
	HBPair left = isBalancedTree(root->left);
	HBPair right = isBalancedTree(root->right);

	p.depth = max(left.depth, right.depth) + 1;

	if(abs(left.depth - right.depth) <= 1){
		p.balanced = true; 
	}else{
		p.balanced = false;
	}

	return p;

}

int main(){
	node* root = buildTree();
	cout << boolalpha << isBalancedTree(root).balanced << endl;	

	return 0;
}