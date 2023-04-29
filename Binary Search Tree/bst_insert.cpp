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


int main(){

	node* root = build();

	bfs(root);

	

	return 0;
}
