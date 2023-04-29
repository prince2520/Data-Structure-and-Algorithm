#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

node* buildTree(int no_of_level){
	int d;
	cin >> d;

	node*root = new node(d);

	queue<node*> q;

	q.push(root);

	int l, r;

	while(!q.empty()){
		node* top = q.front();
		q.pop();

		int l;
		cin >> l;

		if(l != -1){
			top->left = new node(l);
			q.push(top->left);
		}

		int r;
		cin >> r;
		if(r != -1){
			top->right = new node(r);
			q.push(top->right);
		}

	}

	return root;
}

void vectorOrderPrint(node*root, int p, map<int, vector<int>> &m){
	// Base case
	if(root == NULL){
		return;
	}

	// Rec case
	m[p].push_back(root->data); 

	vectorOrderPrint(root->left, p-1, m);

	vectorOrderPrint(root->right, p+1, m);

	return;

}

int main(){
	int no_of_level;
	cin >> no_of_level;

	node* root = buildTree(no_of_level);

	map<int, vector<int>> m; 

	vectorOrderPrint(root, 0, m);

	for(auto it: m){
		if(it.second.size()!=0){
			for(auto v:it.second){
			cout << v <<" ";
			}
		}
	}

	return 0;
}