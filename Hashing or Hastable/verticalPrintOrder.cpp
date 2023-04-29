#include <iostream>
#include <vector>
#include <map>
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

void vectorOrderPrint(node* root, int d, map<int, vector<int>> &m){
	// Base case 
	if(root == NULL){
		return;
	}
	// Rec case 
	m[d].push_back(root->data);

	vectorOrderPrint(root->left, d-1, m);
	vectorOrderPrint(root->right, d+1, m);


	return;
}

int main(){

	node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);

	root->right->left = new node(6);
	root->right->right = new node(7);

	root->right->right->right = new node(9);
	root->left->right->right = new node(8);


	map<int, vector<int>> m;

	int d = 0;
	vectorOrderPrint(root, d, m);


	for(auto n: m){
		for(auto v: n.second){
			cout << v << " ";
		}
		cout << endl;
	}






	return 0;
}