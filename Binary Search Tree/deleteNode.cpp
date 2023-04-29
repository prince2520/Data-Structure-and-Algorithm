#include <iostream>
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


node* deleteInBST(node* root, int data){
	// Base case
	if(root == NULL){
		return NULL;
	}


	// Rec case
	if(root->data == data){
		// Option 1 :- if delete node has no child 
		if(root->left == NULL and root->right == NULL){
			delete root;
			return NULL;
		}

		// Option 2 :- if delete node has 1 child 
		if(root->left!= NULL and root->right == NULL){
			node*temp = root->left;
			delete root;
			return temp;

		} 

		if(root->left == NULL and root->right != NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}

		// Option 3 :- if delete node has 2 child
		node* replace = root->right;

		while(replace->left != NULL ){
			replace = replace->left; 
		}

		root->data = replace->data;

		root->right = insertInBST(root->right, replace->data);

		return root;

	}else if(data < root->data){
		root->left = deleteInBST(root->left, data);
		return root;


	}else{
		root->right = deleteInBST(root->right, data);
		return root;

	}

}



int main(){

	node* root = build();
	bfs(root);
	
	cout << endl;

	int key;
	cin >> key;

	cout << endl;


	root = deleteInBST(root, key);
	bfs(root);



	return 0;
}
