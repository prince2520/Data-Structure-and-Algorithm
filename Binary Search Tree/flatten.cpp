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

class LinkedList{
public:
	node* head;
	node* tail;
};


LinkedList flatten(node* root){
	LinkedList l;
	
	// Base case 
	if(root == NULL){
		l.head = NULL;
		l.tail = NULL;

		return l;
	}

	// Rec case 

	// if node is leaf node
	if(root->left == NULL and root->right == NULL){
		l.head = root;
		l.tail = root;
		return l;
	}

	// if right node is null
	if(root->left != NULL and root->right == NULL){
		LinkedList leftLL = flatten(root->left);
		leftLL.tail->right = root;
		
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}


	// if left node is NULL
	if(root->right != NULL and root->left == NULL){
		LinkedList rightLL = flatten(root->right);

		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;

	}

	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);

	leftLL.tail->right = root;
	root->right  = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;

	return l;

}

int main(){

	node* root = build();
	cout << endl;
	bfs(root);
	
	cout << endl;

	LinkedList l = flatten(root);
	node* temp = l.head;

	while(temp->right!=NULL){
		cout << temp->data << " --> " ;
		temp = temp->right;
	}


	

	return 0;
}
