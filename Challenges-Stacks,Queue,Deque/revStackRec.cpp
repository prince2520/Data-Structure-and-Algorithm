#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &stk, int d){
	// Base case 
	if(stk.empty()){
		stk.push(d);
		return;
	}
	
	// Rec case 
	int data  = stk.top();
	stk.pop();

	insertAtBottom(stk, d);
	stk.push(data);
}

void reverseStackRec(stack<int> &stk){
	// Base case
	if(stk.empty()){
		return;
	}

	// Rec case 

	int data = stk.top();
	stk.pop();

	reverseStackRec(stk);
	insertAtBottom(stk, data);
}


int main(){
	int n;
	cin >> n;

	stack<int> stk;
	int data;


	for(int i=0; i<n; i++){
		cin >> data;
		stk.push(data);
	}

	reverseStackRec(stk);

	while(!stk.empty()){
		cout << stk.top() << endl;
		stk.pop();
	}	

	return 0;
}
