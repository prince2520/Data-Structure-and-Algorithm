#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &head, int d){
	
	// Empty list
	if(head == NULL){
		head = new node(d);
		return;
	}

	// Non-Empty list
	node* n = new node(d);
	n->next = head;

	head = n;
}

void print(node* head, int k){
	if(head==NULL){
		return;
	}

	int i = 0;

	while(head != NULL and i < k ){

		if ( i == k-1){
			cout << head->data;
			return;
		}

		head = head-> next;
		i++;
	}
	cout << endl;
}

int main(){	

	node* head = NULL;

	int n;
	cin >> n;

	while(n!=-1){
		insertAtHead(head,n);
		cin >> n;
	}

	int k;
	cin >> k;

	print(head, k);

	return 0;
}