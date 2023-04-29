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


void insertAtTail(node*&head, int d){
	
	// Empty linked list
	if(head==NULL){
		head = new node(d);
		return;
	}

	// Non-Empty linked list
	node* tail = head;

	while(tail->next!=NULL){
		tail = tail->next;
	}

	tail->next = new node(d);
	return;
}

void print(node*&head){
	// Empty linked list 
	if(head == NULL){
		return;
	}

	// Non-Empty linked list
	while(head->next != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << head->data;
	cout << endl;
}


void kAppend(node*&head, int k, int n){

	// If node or next node empty => return;
	if(head==NULL or head->next==NULL){
		return;
	}

	node*prevPtr = NULL;
	node*currPtr = head;

	int i=0;

	// iterate upto  k element; 
	while(currPtr!=NULL and i<(n-k)){
		prevPtr = currPtr;
		currPtr = currPtr->next;
		i++;
	}

	// Make (k-1)th element->next = null
	prevPtr->next = NULL;

	// Save the kth element address
	node* newHead = currPtr;

	// iterate upto last element
	while(currPtr->next!= NULL){
		currPtr = currPtr->next;
	}

	// Joint lastElement->next = head 
	currPtr->next = head;

	// point to kth element
	head = newHead;
}

int main(){
	int n;
	cin >> n;

	node* head = NULL;

	int d;

	for(int i=0; i<n; i++){
		cin >> d;
		insertAtTail(head, d);
	}

	int k;
	cin >> k;

	if(k>0 and k != n){
		kAppend(head, k%n , n);
	}

	print(head);

	return 0;
}
