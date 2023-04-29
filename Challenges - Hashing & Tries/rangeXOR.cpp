#include <iostream>
#include <climits>
using namespace std;

class node{
public:
	node* right; // represent 1
	node* left; // represent 0
	pair<int,int> p;

	node(int min_idx = INT_MAX, int max_idx = INT_MIN){
		right = NULL;
		left = NULL;
		p.first = min_idx;
		p.second = max_idx;
	}
};

class Trie{
	node* root;
public:
	Trie(){
		root = new node();
	}

	void insert(int num, int idx){

		node* temp = root;

		for(int i=31; i>=0; i--){
			int bit = (num>>i)&1;

			if(bit==0){
				if(temp->left == NULL){
					temp->left = new node();
				}

				int min_idx = temp->left->p.first;
				int max_idx = temp->left->p.second;

				temp->left->p.first = min(min_idx, idx);
				temp->left->p.second = max(max_idx, idx);

				temp = temp->left;

			}else{
				if(temp->right == NULL){
					temp->right = new node();
				}

				int min_idx = temp->right->p.first;
				int max_idx = temp->right->p.second;

				temp->right->p.first = min(min_idx, idx);
				temp->right->p.second = max(max_idx, idx);

				temp = temp->right;
			}
		}
	}

	int rangeXOR(int l, int r, int x){
		node* temp = root;

		int ans = 0;

		int min_idx;
		int max_idx;

		for(int i=31; i>=0; i--){
			int bit = (x>>i)&1;

			min_idx = temp->p.first;
			max_idx = temp->p.second;

			if(bit == 0){
				if(l <= min_idx and max_idx <=r and temp->right!= NULL ){
					temp = temp->right; 
					ans+=(1<<i);
				}else{
					temp = temp->left;
				}
			}else{
				if(l <= min_idx and max_idx <= r and temp->left!= NULL){
					temp = temp->left; 
					ans+=(1<<i);
				}else{
					temp = temp->right;
				}
			}
		}

		return ans^x;
	}
};

int main(){
	int q;
	cin >> q;

	Trie t;

	int opt, x;
	int i = 0;

	for(int j=0; j<q; j++){
		cin >> opt ;

		if(opt==0){
			cin >> x;
			// Insert number
			t.insert(x, i);
			i++;
		}else{
			int l, r;
			cin >> l >> r >> x;

			cout << t.rangeXOR(l-1,r-1,x) << endl;

		}

	}

	return 0;
}