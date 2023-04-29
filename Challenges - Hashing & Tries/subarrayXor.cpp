#include <iostream>
using namespace std;

class node{
public:
	node* right; // represent 1
	node* left; // represent 0

	node(){
		right = NULL;
		left = NULL;
	}
};

class Trie{
	node* root;
public:
	Trie(){
		root = new node();
	}

	void insert(int num){

		node* temp = root;

		for(int i=31; i>=0; i--){
			int bit = (num>>i)&1;

			if(bit==0){
				if(temp->left == NULL){
					temp->left = new node();
				}
				temp = temp->left;
			}else{
				if(temp->right == NULL){
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
	}

	int max_xor(){

		

	}
};

int main(){
	int n;
	cin >> n;

	Trie t;

	int d;

	for(int i=0; i<n; i++){
		cin >> d;
		t.insert(d);
	}

	cout << t.max_xor() << endl;


	return 0;
}