#include <iostream>
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

node* insertInBST(node* root ,int d){
	if(root == NULL){
		return new node(d);
	}

	if(d <= root->data){
		root->left = insertInBST(root->left, d);
	}else{
		root->right = insertInBST(root->right, d);
	}

	return root;
}

void printPre(node* root){
	// Base case 
	if(root == NULL){
		return;
	}

	// Rec case 
	cout << root->data << " ";

	printPre(root->left);
	printPre(root->right); 
}

void rangedBST(node* root, int k1, int k2){
	// Base case 
	if(root == NULL){
		return;
	}
	
	if(k1 == root->data){
		cout << root->data << " ";
		return; 
	}

	// Rec case
	if(k1 < root->data){
		rangedBST(root->left, k1, k2);
	}



}


int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;		


		int d;
		node* root = NULL;
		for(int i=0; i<n; i++){
			cin >> d;
			root = insertInBST(root, d);
		}

		int a, b;
		cin >> a >> b;

		// Output first line 
		cout << "# Preorder : ";
		printPre(root);
		cout << endl;

		// Output second line
		cout << "# Nodes within range are : ";
	


		delete root;
	}
	

	return 0;
}