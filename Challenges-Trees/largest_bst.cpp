#include <iostream>
#include <climits>
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

node* createTree(int *pre, int *in, int s, int e){
	static int i=0;

	// Base case 
	if(s>e){
		return NULL;
	}

	// Rec case
	int index = -1;
	for(int j=s; j<=e; j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}

	i++;

	// create new node
	node* root = new node(in[index]);

	root->left = createTree(pre, in, s, index-1);
	root->right = createTree(pre, in, index+1, e);

	return root;
}

class BTPair{
public:
	int max_num;
	int min_num;
	int noOfBSTNode;
};

BTPair largestBSTLength(node* root, int &maxBSTNodes){
	BTPair b;

	// Base case 
	if(root == NULL){
		b.max_num = INT_MIN;
		b.min_num = INT_MAX;
		b.noOfBSTNode = 0;
		return b;
	}

	// Rec case 

	BTPair leftAns = largestBSTLength(root->left, maxBSTNodes);
	BTPair rightAns = largestBSTLength(root->right, maxBSTNodes);

	b.noOfBSTNode = 1;
	b.max_num = root->data;
	b.min_num = root->data;

	if(leftAns.max_num <= root->data){
		b.max_num = max(root->data, max(leftAns.max_num, rightAns.max_num));
	    b.min_num = min(root->data, min(leftAns.min_num, rightAns.min_num));

		if(root->right == NULL){
			b.noOfBSTNode = leftAns.noOfBSTNode + 1;
		}

		if(root->right!=NULL and root->data < rightAns.min_num ){
		    b.noOfBSTNode = leftAns.noOfBSTNode + rightAns.noOfBSTNode + 1;
		}

	}

	maxBSTNodes = max(maxBSTNodes, b.noOfBSTNode);

	return b;
}


int main(){
	int n;
	cin >> n;

	// Pre-Order 
	int *pre = new int[1000];
	for(int i=0; i<n; i++){
		cin >> pre[i];
	}

	// In-Order
	int *in = new int[1000];
	for(int i=0; i<n; i++){
		cin >> in[i];
	}

	// Create BST root
	node* root = createTree(pre, in, 0, n-1);

	int maxBSTNodes = -1;
	largestBSTLength(root, maxBSTNodes);

	cout << maxBSTNodes << endl;

	delete [] pre;
	delete [] in;

	return 0;
}