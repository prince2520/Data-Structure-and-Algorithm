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
 
node* buildTree(int *arr, int s, int e){
	// Base case
	if(s>e){
		return NULL;
	}

	// Rec case 

	int mid = (s+e)/2;

	node* root = new node(arr[mid]);

	root->left = buildTree(arr, s, mid-1);
	root->right = buildTree(arr, mid+1, e);

	return root;
}

void print(node* root){

	// Base case 
	if(root == NULL){
		return;
	}

	// Rec case 
	cout << root->data << " " ;
	
	print(root->left);
	print(root->right);
}

void replaceSum(node*root, int &rightSumTree){
	// Base case 
	if(root == NULL){
		return;
	}

	// Rec case

	replaceSum(root->right, rightSumTree);
	
	root->data = rightSumTree + root->data;
	
	rightSumTree = root->data;

	replaceSum(root->left, rightSumTree);

}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	node* root = buildTree(arr, 0, n-1);
	int rightSum = 0;
	replaceSum(root, rightSum);

	print(root);

	return 0;
}