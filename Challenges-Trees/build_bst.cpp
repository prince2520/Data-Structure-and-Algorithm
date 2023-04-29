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

node* buildTree(int *arr, int s, int e){
	// Base case 
	if(s > e){
		return NULL;
	}

	// Rec case

	int mid = (s+e)/2;

	node* root = new node(arr[mid]);

	root->left = buildTree(arr, s, mid-1);
	root->right = buildTree(arr, mid+1, e);

	return root;

}

void printPre(node* root){
	if(root == NULL){
		return;
	}

	cout << root->data << " ";

	printPre(root->left);
	printPre(root->right); 
}


int main(){

	int t;
	cin >> t;

	int *arr = new int[1000]; 

	while(t--){
		int n;
		cin >> n;

		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		node*root = buildTree(arr, 0, n-1);

		printPre(root);

		cout << endl;

	}

	delete [] arr;

	return 0;
}