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

	// Empty case 
	if(head == NULL){
		head = new node(d);
		return;
	}

	// Non-empty case 
	node* temp = head;

	while( temp->next!=NULL ){
		temp = temp->next;
	}

	temp->next = new node(d);

}

void print(node* head){
	while(head!= NULL){
		cout << head->data << " " ;
		head = head->next;
	}
}

void oddEven(node*&head){
	// Empty case 
	if(head == NULL and head->next == NULL){
		return;
	}

	node* currPtr = head;
	node* prevPtr = NULL;
	node* nextPtr;
	node* oddPtr = NULL;

	while(currPtr != NULL){

		if((currPtr->data%2)!=0){
			if(oddPtr != NULL){
				nextPtr = currPtr->next;
				prevPtr->next = nextPtr;
				node* oddNextPtr = oddPtr->next;

			    oddPtr->next= currPtr;
			    currPtr->next = oddNextPtr;

			    oddPtr = currPtr;
			    currPtr = nextPtr;
			}else{
				oddPtr = currPtr;
				prevPtr = currPtr;
				currPtr = currPtr->next;
			}
			
		}else{
			prevPtr = currPtr;
			currPtr = currPtr->next;
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
	oddEven(head);
	print(head);

	return 0;
}