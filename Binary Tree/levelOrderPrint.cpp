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

void print(node* root){
	if(root == NULL){
		return;
	}

	cout << root->data << " ";

	print(root->left);
	print(root->right);
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

void printKthLevel(node *root, int k){
	if(root == NULL){
		return;
	}

	if(k == 1){
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
}

int main(){

	node* root = buildTree();

	// Pre Order
	//print(root);
	
	int h = height(root);
	for(int i=1; i<=h; i++){
		printKthLevel(root,i);
		cout << endl;
	}

	return 0;
}