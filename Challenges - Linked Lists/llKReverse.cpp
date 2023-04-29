#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int d){
		data = d;
		next = NULL;
	}
};


void insertAtTail(node*&head, int data){
	if(head == NULL){
		head = new node(data);
		return;
	}

	node*tail = head;

	while(tail->next!=NULL){
		tail = tail->next;
	}

	tail->next= new node(data);
	return;
}


void print(node*head){
	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void reverse(node*&head, int k, node*& prevPtr, node*&currPtr){
	node* P = NULL;
	node* C = head;
	node* N;

	int i = 0;

	while(C!=NULL and i < k){
		N = C->next;
		C->next = P;

		P = C;
		C = N;

		i++;
	};

	prevPtr = P;
	currPtr = C;
}


node* kReverse(node*head, int k){

	// Base case
	if(head==NULL){
		return head;
	}

	// Rec case ;
	node* prevPtr;
	node* currPtr = head;
	 
	reverse(head, k, prevPtr, currPtr);

	head->next = kReverse(currPtr, k);

	return prevPtr;
}


int main(){
	int n, k;
	cin >> n >> k; 

	node* head = NULL;

	for(int i=0; i<n; i++){
		int d;
		cin >> d;

		insertAtTail(head, d);
	}

	head = kReverse(head, k);	

	print(head);

	return 0;
}