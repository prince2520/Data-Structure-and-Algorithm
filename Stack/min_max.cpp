#include <iostream>
#include <vector>
using namespace std;

class MinMaxStack{
	vector<int> stack;
	vector<int> min_stack;
	vector<int> max_stack;

public:

	void push(int data){
		int current_min = data;
		int current_max = data;

		if(min_stack.size()){
			current_max = max(data, max_stack[max_stack.size()-1]);
			current_min = min(data, min_stack[min_stack.size()-1]);
		}

		stack.push_back(data);
		min_stack.push_back(current_min);
		max_stack.push_back(current_max);
	}

	int get_min(){
		return min_stack[min_stack.size() - 1];
	}

	int get_max(){
		return max_stack[max_stack.size() - 1];

	}

	int top(){
		return stack[stack.size()-1];

	}

	void pop(){
		min_stack.pop_back();
		max_stack.pop_back();
		stack.pop_back();
	}
};

int main(){

	MinMaxStack s;

	s.push(1);
	s.push(5);
	s.push(3);
	s.push(8);


	cout << s.get_max() << endl;
	s.pop();
	cout << s.get_min() << endl;
	cout << s.get_max() << endl;

	s.pop();
	s.pop();
	cout << s.top() << endl;
	cout << s.get_max() << endl;	

	return 0;
}