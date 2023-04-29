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
	// Empty
	if(head == NULL){
		head = new node(d);
		return;
	}

	// Non Empty
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = new node(d);

	return;
}

void print(node* head){

	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

void reverse(node*&head){

	// If empty
	if(head == NULL and head->next == NULL){
		return;
	}

	// If Non-Empty
	node* C = head;
	node* P = NULL;
	node* N ; 
	while(C!=NULL){
		N = C->next;
		C->next = P;

		P = C;
		C = N;
	}

	head = P;
}

bool isPalindrome(node* head, int n){

	// If Empty
	if(head==NULL){
		return false;
	}

	// If single element then its always palindrome
	if(head->next == NULL){
		return true;
	}

	int mid = n/2;

	node* midElem = head;
	
	// Iterate upto mid term
	int i=1;
	while(i<mid){
		midElem  = midElem->next;
		i++;
	}

	node* midNextElem = midElem->next;
	midElem->next = NULL;

	// Reverse mid+1 element 
	reverse(midNextElem);

	// Check the condition for palindrome
	while(midNextElem!=NULL and head!= NULL){
		if(midNextElem->data != head->data){
			return false;
		}

		midNextElem = midNextElem->next;
		head = head->next;
	}

	return true;
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

	cout << boolalpha << isPalindrome(head, n);


	return 0;
}