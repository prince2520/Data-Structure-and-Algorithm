#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class node {
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

node* build(){
	int d;
	cin >> d;

	 node* root = NULL;

	while(d != -1){
		root = insertInBST(root, d);
		cin >> d;
	}

	return root;
}

void bfs(node* root){
	queue <node *> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
		q.pop();

		if(f == NULL){
			cout << endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			cout << f->data << " ";
			if(f->left){
				q.push(f->left);
			}

			if(f->right){
				q.push(f->right);
			}

		}
	}
}


bool isBST(node *root, int minVal = INT_MIN, int maxVal = INT_MAX){
	// Base case 
	if(root == NULL){
		return true;
	}

	// Rec case 
	if( minVal <= root->data and root->data <= maxVal and isBST( root->left, minVal, root->data ) and isBST(root->right, root->data, maxVal)){
		return true;
	}

	return false;
}



int main(){

	node* root = build();
	cout << endl;
	bfs(root);
	
	cout << endl;

	cout << boolalpha << isBST(root);
	

	return 0;
}
