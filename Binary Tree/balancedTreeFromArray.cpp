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

node* buildTreeFromArray(int *arr, int s, int e){
	// Base case
	if(s>e){
		return NULL;
	}

	// Rec case 
	int mid = (s+e)/2;
	node* root = new node(arr[mid]);

	root->left = buildTreeFromArray(arr, s, mid-1);
	root->right = buildTreeFromArray(arr, mid+1, e);

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
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = 7;

	node* root = buildTreeFromArray(arr, 0, n-1);

	bfs(root);

	return 0;
}