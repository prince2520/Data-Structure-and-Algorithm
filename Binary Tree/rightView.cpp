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

void printRightView(node* root, int lvl, int &maxLvl){

	// Base case 
	if(root == NULL){
		return;
	}

	// Rec case 
	if(maxLvl < lvl){
		cout << root->data << " ";
		maxLvl = lvl;
	}

	printRightView(root->right, lvl+1, maxLvl);
	printRightView(root->left, lvl+1, maxLvl);
}


int main(){

	node* root = buildTree();

	int maxLvl = -1;
	printRightView(root, 0, maxLvl);


	return 0;
}