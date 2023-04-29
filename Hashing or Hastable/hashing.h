#include <iostream>
#include <cstring>
using namespace std;

template <typename T>

class node{
public:
	string key;
	T value;
	node <T>*next;

	node(string k, T val){
		this->key = k;
		value = val;
		next = NULL; 
	}

	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template <typename T>

class hastable{

	node <T> **table;
	int current_size;
	int table_size;

	int hashFn(string key){

		int p = 1;
		int idx = 0;

		for(int j=0; j<key.length(); j++){
			idx = idx + (key[j]*p)%table_size;

			idx = idx%table_size;

			p = (p*27)%table_size;

		}

		return idx;
	}

	void rehash(){

		node<T> **oldTable = table;
		
		int oldTableSize = table_size;
		
		table_size = 2*table_size;

		table = new node<T>*[table_size];

		for(int i=0; i<table_size; i++){
			table[i] = NULL;
		}

		current_size = 0;

		for(int i=0; i<oldTableSize; i++){

			node<T>*temp = oldTable[i];

			while(temp!=NULL){

				insert(temp->key, temp->value);
				temp= temp->next;

			}
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}

		delete [] oldTable;
	}

public:
	hastable(int ts=7){
		table_size = ts;
		table = new node<T>*[table_size];
		current_size = 0;

		for(int i=0; i<table_size; i++){
			table[i] = NULL;
		}
	}

	void insert(string key, T val){

		int idx = hashFn(key);

		node<T>*n = new node<T>(key, val);

		n->next = table[idx];
		table[idx] = n;

		current_size++;

		//rehash 

		float load_factor = current_size/(1.0*table_size);

		if( load_factor > 0.7){
			rehash();
		}

	}

	void print(){

		for(int i=0; i<table_size; i++){
			cout << "Bucket " << i << " ->";

			node <T> *temp = table[i];

			while(temp!=NULL){
				cout << temp->key << " -> ";
				temp = temp->next;
			}

			cout << endl;
		}

	}

	T* search(string key){

		int idx = hashFn(key);

		node<T>* temp = table[idx];

		while(temp!=NULL){
			if(temp->key == key){
				return &temp->value;
			}

			temp = temp->next;
		}

		return NULL;

	}

	T& operator[](string key){
		T* f = search(key);

		if(f==NULL){
			T garbage;
			insert(key, garbage);

			f = search(key);
		}

		return *f;

	}

	void erase(string key){

	}

};

