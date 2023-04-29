#include <iostream>
#include <queue>
#include <deque>
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

	node* root = new node(d);
	
	queue <node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		int l;
		cin >> l;

		if(l != -1){
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

void top_view(node* root, int rLvl, int lLvl, int &rMax, int &lMax, deque<int> &d){
	// Base case
	if(root == NULL){
		return;
	}

	if(lLvl>lMax){
		lMax = lLvl;
		d.push_front(root->data);
	}

	if(rLvl > rMax){
		rMax = rLvl;
		d.push_back(root->data);
	}

	// Rec case
	top_view(root->left, rLvl-1, lLvl+1, rMax, lMax, d);
	top_view(root->right, rLvl+1, lLvl-1, rMax, lMax, d);
}


int main(){
	node* root = buildTree();

	deque<int> d; 

	int rMax = 0;
	int lMax = -1;

	top_view(root, 0, 0, rMax, lMax, d);

	while(!d.empty()){
		cout << d.front() << " ";
		d.pop_front();
	}

	return 0;
}