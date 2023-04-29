#include <iostream>
#include <queue>
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

	if(d == -1){
		return NULL;
	}

	node *root = new node(d);

	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void print(node* root){
	if(root == NULL){
		return;
	}

	cout << root->data << " ";

	print(root->left);
	print(root->right);
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

	node* root = buildTree();

	// Pre Order
	//print(root);
	//cout << endl;

	bfs(root);

	return 0;
}