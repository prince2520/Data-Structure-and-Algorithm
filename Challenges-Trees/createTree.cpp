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

node* createTree(int *inorder, int s, int e, int *preorder){
	static int i=0;

	// Base case 
	if(s>e){
		return NULL;
	}

	// Rec case
	int index = -1;

	for(int j=s; j<=e; j++){
		if(inorder[j] == preorder[i]){
			index = j;
			break;
		}
	}

	node*root = new node(inorder[index]);
	i++;

	root->left = createTree(inorder, s, index-1, preorder);
	root->right = createTree(inorder, index+1, e, preorder);


	return root;
}

void print(node* root){
	// Base case 
	if(root == NULL){
		return;
	}

	if(root->left==NULL)
		cout << "END => ";
	else
		cout << root->left->data<< " => ";

	cout << root->data;

	if(root->right==NULL)
		cout << " <= END" << endl;
	else
		cout << " <= " << root->right->data<<endl;

	print(root->left);
	print(root->right); 
}

int main(){

	// Pre-Order
	int n;
	cin >> n;

	int *preArr = new int[10000];

	for(int i=0; i<n; i++){
		cin >> preArr[i];
	}

	// In-Order 
	int m;
	cin >> m;

	int *inArr = new int[10000];

	for(int i=0; i<m; i++){
		cin >> inArr[i];
	}

	node* root = createTree(inArr, 0, m-1, preArr);


	print(root);


	delete [] preArr;
	delete [] inArr;	

	return 0;
}