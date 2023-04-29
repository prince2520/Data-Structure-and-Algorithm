#include <iostream>
#include <stack>
using namespace std;

class Queue{
	stack <int> s1, s2;
public:
	void push(int d){
		s1.push(d);
	}

	void pop(){
		if(s1.empty()){
			return;
		}

		while(s1.size() > 1){
			int top = s1.top();
			s1.pop();
			s2.push(top);
		}

		s1.pop();

		while(!s2.empty()){
			int top = s2.top();
			s2.pop();
			s1.push(top);
		}
	}

	bool empty(){
		return s1.size() == 0;

	}

	int front(){
		while(s1.size() > 1){
			int top = s1.top();
			s1.pop();
			s2.push(top);
		}

		int f = s1.top();

		while(!s2.empty()){
			int top = s2.top();
			s2.pop();
			s1.push(top);
		}


		return f;
	}
};

int main(){

	int n;
	cin >> n;

	Queue q;

	for(int i=0; i<n; i++){
		q.push(i);
	}

	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}

	

	return 0;
}