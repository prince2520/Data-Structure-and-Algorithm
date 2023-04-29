#include <iostream>
#include <string>
#include <map>
using namespace std;

class node {
public:
	char d;
	map<char,node*> children;
	bool terminal;

	node(char d){
		this->d = d;
		terminal = false;
	}
};

void print(node* root, string str){
	// Base case 
	if(root == NULL){
		return;
	}

	if(root->terminal){
		cout << str+root->d<< endl;
	}

	for(auto it: root->children){
		print(it.second, str+root->d);
	}
}

class Trie{
	node* root;
public:
	Trie(){
		root = new node('\0');
	}

	void insert(string str){

		node* temp = root;

		for(int i=0; i<str.length(); i++){
			char ch = str[i];

			if(temp->children.count(ch) == 0){
				node* n = new node(ch);
				temp->children[ch] = n;
				temp= n;
			}else{
				temp = temp->children[ch];
			}
		}

		temp->terminal = true;
	}

	bool search(string qStr){
		node* temp = root;

		string s="";
		for(int i=0; i<qStr.length(); i++){
			char ch = qStr[i];

			if(temp->children.count(ch)!=0){
				temp = temp->children[ch];
			}else{
				return false;
			}
		}

		if(temp->terminal){
			cout << qStr << endl;
		}

		for(auto it : temp->children){
			print(it.second,qStr);

		}

		return true;
	}
};

int main(){
	int n;
	cin >> n;

	Trie t;

	string str;
	for (int i = 0; i < n; i++){
		cin >> str;
		t.insert(str);
	}

	int q;
	cin >> q;

	string qStr;
	for(int i=0; i<q; i++){
		cin >> qStr;
		if(t.search(qStr)){

		}else{
			cout << "No suggestions" << endl;
			t.insert(qStr);
		}
	}

	return 0;
}