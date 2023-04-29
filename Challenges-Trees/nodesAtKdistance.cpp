#include <iostream>
#include <vector>
#include<algorithm>
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

node* buildTree(int* pre, int *in, int s, int e){
	static int i=0;
	// Base case
	if(s>e){
		return NULL;
	}

    // Rec case 
	int index = -1;

	for(int j=s; j<=e; j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}

	i++;

	node* root = new node(in[index]);

	root->left = buildTree(pre, in, s, index-1);
	root->right = buildTree(pre, in, index+1, e);

	return root;
}


void printKthLvl(node* root, int k, int lvl, vector<int> &v){
	// Base case 
	if(root == NULL){
		return;
	}

	if(lvl == k){
		v.push_back(root->data);
		return;
	}
	// Rec case

	printKthLvl(root->left, k, lvl+1, v);
	printKthLvl(root->right, k, lvl+1, v); 
}

int printKthDistanceNode(node* root, int k, int key, vector<int> &v){
	// Base case 
	if(root == NULL){
		return -1;
	}

	if(root->data == key){
		printKthLvl(root, k, 0, v);
		return 0;
	}

	// Rec case 

	int leftAns = printKthDistanceNode(root->left, k, key, v);

	if(leftAns!=-1){
		if(leftAns+1 == k){
			v.push_back(root->data);
		}else{
			printKthLvl(root->right, k-2-leftAns, 0, v);
		}
		return leftAns+1;
	}

	int rightAns = printKthDistanceNode(root->right, k, key, v);

	if(rightAns!=-1){
		if(rightAns+1 == k){
			v.push_back(root->data);
		}else{
			printKthLvl(root->left, k-2-rightAns, 0, v);
		}
		return rightAns+1;
	}

	return -1;
}

int main(){
	int n;
	cin >> n;

	int pre[1000];
	for(int i=0; i<n; i++){
		cin >> pre[i];
	}
	
	int in[1000];
	for(int i=0; i<n; i++){
		cin >> in[i];
	}

	node* root = buildTree(pre, in, 0, n-1);

	int t;
	cin >> t;


	while(t--){
		int d, k;
		cin >> d >> k;

		vector <int> v;


		int ans = printKthDistanceNode(root, k, d, v);
		
		sort(v.begin(), v.end());
		
		if(ans == -1 and v.empty()){
			cout << 0 ;
		} else{
			for(auto it:v){
				cout << it << " ";
			}

		}
		cout << endl;
	}

	return 0;
}