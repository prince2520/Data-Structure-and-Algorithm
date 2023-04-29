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

int maxPathSum(node* root, int &maxVal){
	// Base case
	if( root == NULL ){
		return 0;
	}

	// Rec case
	int leftSum = maxPathSum(root->left, maxVal);
	int rightSum = maxPathSum(root->right, maxVal);

	maxVal = max(maxVal, root->data + leftSum + rightSum);

	return max(max(leftSum, rightSum) + root->data, 0);
}




int main(){

	node* root = buildTree();

	int maxVal = 0;

	maxPathSum(root, maxVal);

	cout << maxVal << endl;


	

	return 0;
}
