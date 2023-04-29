#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
	// Base case
	if(s.empty()){
		s.push(x);
		return;
	}

	// Rec case 
	int data = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(data);
}

void reverseStackRec(stack<int> &s){
	// Base case 
	if(s.empty()){
		return;
	}

	// Rec case 
	int x = s.top();
	s.pop();

	reverseStackRec(s);

	insertAtBottom(s, x);
}

int main(){
	stack <int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverseStackRec(s);

	while(!s.empty()){
		cout << s.top() << endl;
		s.pop(); 
	}
	

	return 0;
}