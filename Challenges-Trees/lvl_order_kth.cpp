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

	string l;
	cin >> l;

	if(l == "true"){
		root->left = buildTree();
	}

	string r;
	cin >> r;

	if(r == "true"){
		root->right = buildTree();

	}

	return root;
}

int height(node* root){
	// Base case 
	if(root == NULL){
		return 0;
	}

	// Rec case
	int leftAns = height(root->left);
	int rightAns = height(root->right);

	return max(rightAns, leftAns) + 1; 
}

void printKthLvl(node*root, int k, int lvl){
	// Base case 
	if(root == NULL){
		return;
	}

	if(k==lvl){
		cout << root->data << " ";
		return;
	}

	// Rec case 
	if(k%2==0){
		printKthLvl(root->right, k, lvl+1);
		printKthLvl(root->left, k, lvl+1);
	}else{
		printKthLvl(root->left, k, lvl+1);
		printKthLvl(root->right, k, lvl+1);
	}
}

void zigZag(node* root){
	int h= height(root);

	for(int i=1; i<=h; i++){
		printKthLvl(root, i, 1);
	}
}

int main(){
	node* root = buildTree();

	zigZag(root);	

	return 0;
}