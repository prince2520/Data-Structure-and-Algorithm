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

int search(node*root, int key, int level){
	//Base case 
	if(root == NULL){
		return -1;
	}

	if(root->data == key){
		return level;
	}

	// Rec case
	int leftAns = search(root->left, key, level+1);
	if(leftAns!=-1){
		return leftAns;
	}

	return search(root->right, key, level+1);

}

int findDistance(node *root, int a, int b){

	node* lcaRoot = lca(root, a, b);

	int p1 = search(lcaRoot, a, 0);
	int p2 = search(lcaRoot, b, 0);

	return p1 + p2;
 
}



int main(){

	node* root = buildTree();

	cout << findDistance(root, 4, 7) << endl;

	return 0;
}
