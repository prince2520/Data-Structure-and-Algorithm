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
	node *root = new node(d);

	string leftStr;
	cin >> leftStr;

	if(leftStr == "true"){
		root->left = buildTree();
	}

	string r;
	cin >> r;

	if(r == "true"){
   	    root->right = buildTree();
	}

	return root;
}

bool structIdentity(node*root1, node*root2){
	// Base case
	if(root1 == NULL and root2 == NULL){
		return true;
	}

	if((root1 == NULL and root2 != NULL) || (root1 != NULL and root2 ==NULL)){
		return false;
	}

	// Rec case

	bool left = structIdentity(root1->left, root2->left);
	bool right = structIdentity(root1->right, root2->right);

	if(left and right){
		return true;
	}

	return false;
}



int main(){
	node* root1 = buildTree();
	node* root2 = buildTree();

	cout << boolalpha << structIdentity(root1, root2) << endl;

	return 0;
}