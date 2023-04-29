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

void insertAtHead(node*&head, int d){

	if(head==NULL){
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n->next = head;
	head = n;
}

void print(node*head){
	while(head!=NULL){
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

int length(node*head){
	int cnt = 0;
	
	while(head != NULL){
		cnt++;
		head = head->next;
	}

	return cnt;
}

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

void insertIntMiddle(node*&head, int data , int p){

	if(head==NULL or p==0){
		insertAtHead(head, data);
		return;
	}else if(p > length(head)){
		insertAtTail(head, data);
	}else{
		int jump=1;
		node*temp = head;

		while(jump <= p-1){
			temp = temp->next;
			jump++;
		}

		node *n = new node(data);
		n->next = temp->next;

		temp->next = n;
	}
}

void deleteHead(node*&head){
	if(head == NULL){
		return;
	}

	node*temp = head->next;

	delete head;

	head = temp;
}


bool search(node*head, int key){

	node*temp = head;
	
	while(temp!=NULL){
		
		if(temp->data == key){
			return true;
		}

		temp = temp->next;
	}

	return false;
}


bool searchRecursive(node*head, int key){
	// Base case 
	if(head == NULL){
		return false;
	}

	// Rec case
	if(head->data == key){
		return true;
	}else{
		return searchRecursive(head->next, key);
	}
}

node* take_input(){
	int d; 
	cin >> d;

	node*head = NULL;
	while(d!=-1){
		insertAtHead(head, d);
		cin >> d;
	}

	return head;
}

ostream& operator<<(ostream &os, node*head){
	print(head);
	return os;
}

istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}

void reverse(node*&head){
	node*C = head;
	node*P = NULL;
	node*N;

	while(C!=NULL){

		N = C->next;
		C->next = P;

		P = C;
		C = N;
	}

	head = P;
}

node* midpoint(node*head){
	if(head == NULL or head->next == NULL){
		return head;
	}

	node*slow = head;
	node*fast = head->next;

	while( fast!= NULL and fast->next!=NULL ){
		fast = fast->next->next;
		slow = slow->next; 
	}

	return slow;
}

node* recReverse(node*head){
	// Base Case 
	if(head->next == NULL or head == NULL){
		return head;
	}
	
	//Rec case

	node* shead = recReverse(head->next);

	head->next->next = head;

	head->next = NULL;

	return shead;
}

node* merge(node*a, node*b){
	// Base case
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	node*c; 
	
	// Rec case 
	if(a->data > b->data){
		c = b;
		c->next = merge(a, b->next);
	}else{
		c = a;
		c->next = merge(a->next, b);
	}
	return c;
}

node* mergeSort(node*head){
	// Base case 
	if(head== NULL or head->next==NULL){
		return head;
	}

	// Rec case
	node* mid = midpoint(head);
	node* a = head;
	node* b = mid->next;

	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a, b);
	return c;
}



int main(){
	node*head;
	//node*head2;
	//print(head);

	cin >> head;
	cout << head ;

	head = mergeSort(head);

	//node*mid = midpoint(head);

	cout << head << endl;


	//reverse(head);
	//head = recReverse(head);
	//cout << head;
	/*node*head = NULL;

	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 0);

	insertIntMiddle(head, 4, 3);
	insertAtTail(head, 7);

	deleteHead(head);
	print(head);

	bool ans = searchRecursive(head, 5);

	if(ans){
		cout << "Element found! " << endl; 
	}else{
		cout << "Element not found " << endl; 
	}*/

	return 0;
}