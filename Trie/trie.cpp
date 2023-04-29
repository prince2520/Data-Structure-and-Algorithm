#include <iostream>
#include <unordered_map>
using namespace std;

class node{
public:
	char data;
	unordered_map<char, node*> children;
	bool terminal;

	node(int d){
		data = d;
		terminal = false;
	}
};

class Trie{
	node* root;
	int cnt;

public:
	Trie(){
		root = new node('\0');
	}

	void insert(char *w){
		node* temp = root;

		for(int i=0; w[i]!='\0'; i++){

			char ch = w[i];

			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}else{
				node* n = new node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}

		temp->terminal = true;
	}


	bool find(char *w){
		node* temp = root;

		for(int i=0; w[i]!='\0'; i++){
			char ch =  w[i];

			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}else{
				return false;
			}
		}

		return temp->terminal;
	}

};

int main(){
	Trie t;

	char words[][10] = {"a", "hello", "not", "news", "apple"};
	
	char w[10];

	cin >> w;

	for(int i=0; i<5; i++){
		t.insert(words[i]);
	}

	if(t.find(w)){
		cout << "Present!" << endl;
	}else{
		cout << "Not Present!" << endl;
	}

	return 0;
}