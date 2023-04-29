#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;

	node(int d){
		data = d;
		right = NULL;
		left = NULL;
	}
};

node* buildTree(){
	int d;
	cin >> d;

	if(d == -1){
		return NULL;
	}

	node* root = new node(d);

	root->left = buildTree();
	root->right = buildTree();

	return root; 
}

void printKthLevel(node *root, int k){
	if(root == NULL){
		return;
	}

	if(k == 0){
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
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

int printAtDistanceK(node *root, node *target, int k){
	// Base case 
	if(root == NULL){
		return -1;
	}

	// Rec case 
	if(root == target){
		printKthLevel(root, k);
		return 0;
	}

	int dL = printAtDistanceK(root->left, target, k);

	if(dL != -1){
		if(dL+1 == k){
			cout << root->data << " ";
		}else{
			printKthLevel(root->right, k-2-dL);
		}

		return dL + 1;
	}

	int dR = printAtDistanceK(root->right, target, k);

	if(dR != -1){
		if(dR+1 == k){
			cout << root->data << " ";
		}else{
			printKthLevel(root->left, k-2-dR);
		}
		return dR + 1;
	} 
	return -1;
}


int main(){

	node* root = buildTree();

	bfs(root);

	node* target = root->left->left;

	printAtDistanceK(root, target, 3); 
	

	return 0;
}
