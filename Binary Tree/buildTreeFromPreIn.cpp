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

node* createTreeFromTrav(int *pre, int *in, int s, int e){
	static int i = 0;

	if(s>e){
		return NULL;
	}

	node* root = new node(pre[i]);

	int index = -1;

	for(int j=s; j<=e; j++){
		if(pre[i] == in[j]){
			index = j;
			break;
		}
	}

	i++;

	root->left = createTreeFromTrav(pre, in, s, index-1);
	root->right = createTreeFromTrav(pre, in, index+1, e);

	return root;
}

int main(){
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(pre)/ sizeof(int);

	node* root = createTreeFromTrav(pre, in, 0, n-1);

	bfs(root);	

	return 0;
}