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
		tail = tail -> next;
	}

	tail->next= new node(data);
	return;
}

void print(node* head){

	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;

}


void input(node*& head){
	
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int d;
		cin >> d;
		insertAtTail(head, d);
	}
}

node* merge(node* head1, node* head2){
	// Base case
	if(head1 == NULL){
		return head2;
	}

	if(head2 == NULL){
		return head1;
	}


	// Rec case
	node* c;

	if(head1->data < head2->data){
		c = head1;
		c->next =  merge(head1->next, head2);
	}else{
		c = head2;
		c->next = merge(head1, head2->next);
	}

	return c;


}

int main(){
	int t;
	cin >> t;

	for(int i=0; i<t; i++){
		
		node* head1 = NULL;
		node* head2 = NULL;
		
		input(head1);
		input(head2);

		node *head = merge(head1, head2);

		print(head);
	}

	return 0;
}