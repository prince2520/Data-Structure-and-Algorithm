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

void print(node* head){
	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

node* insertion_sort(node* &head){
	if(head==NULL and head->next==NULL){
		return head;
	}

	node* curr = head->next; 
	node* prev = head;


	while(curr!=NULL){
		if(curr->data < prev->data){

		}

		
			
	}
	
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
	insertion_sort(head);

	print(head);

	return 0;
}
