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

node* insertInBST(node* root, int d){

	// Base case 
	if(root == NULL){
		return new node(d);
	}

	// Rec case 
	if( d <= root->data ){
		root->left = insertInBST(root->left, d);
	}else{
		root->right = insertInBST(root->right, d);
	}

	return root;

}

node* buildTree(int*treeVals, int n){

	node* root = NULL;

	for(int i=0;i<n; i++){
		root = insertInBST(root, treeVals[i]);
	}

	return root;
}


node* deleteNode(node* root, int d){

	// Base case
	if(root == NULL){
		return NULL;
	}

	// Rec case 
	if(root->data == d){
		// Opt 1 - No node
		if(root->left == NULL and root->right == NULL){
			delete root;
			return NULL;
		}

		// Opt 2 - One node
		if(root->left != NULL and root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}

		if(root->left == NULL and root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}

		// Opt 3 - Two node 

		node* temp = root->right;

		while(temp->left != NULL){
			temp = temp->left;
		} 

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);

	}else if(d < root->data ){
		root->left = deleteNode(root->left, d);
	}else{
		root->right = deleteNode(root->right, d);
	}

	return root;
}

void print(node* root){
	// Base case 
	if(root == NULL){
		return;
	}

	// Rec case 
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}


int main(){
	int t;
	cin >> t;

	for(int k =0; k<t; k++){
		int n;
		cin >> n;

		int treeVals[1000];
		for(int i=0; i<n; i++){
			cin >> treeVals[i];
		}

		int m;
		cin >> m;

		int *deleteVals = new int[1000];
		for(int j=0; j<m; j++){
			cin >> deleteVals[j];
		}

		node* root = buildTree(treeVals, n);

		for(int i=0; i<m; i++){
			root = deleteNode(root, deleteVals[i]);	
		}

		print(root);
		cout << endl;
	}

	return 0;
}