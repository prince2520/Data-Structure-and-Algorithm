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

	if(d==-1){
		return NULL;
	}

	node* root = new node(d);

	queue <node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		int l;
		cin >> l;

		if(l!=-1){
			temp->left = new node(l);
			q.push(temp->left);
		}

		int r;
		cin >> r;

		if(r!=-1){
			temp->right = new node(r);
			q.push(temp->right);
		}
	}

	return root;
}

void left_view(node* root, int lvl, int &maxLvl){
	// Base case 
	if(root == NULL){
		return;
	}

	if(lvl>maxLvl){
		cout << root->data << " ";
		maxLvl = lvl;
	}

	// Rec case
	left_view(root->left, lvl+1, maxLvl);
	left_view(root->right, lvl+1, maxLvl);
}

int main(){
	node* root = buildTree();

	int maxLvl = -1;

	left_view(root, 0, maxLvl);

	return 0;
}