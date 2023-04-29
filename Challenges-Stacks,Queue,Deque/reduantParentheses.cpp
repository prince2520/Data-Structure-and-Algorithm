#include <iostream>
#include <stack>
using namespace std;


bool redundant_parentheses(char *ch){
	stack<char> stk;

	for(int i=0; ch[i]!='\0'; i++){

		char c = ch[i];

		if(c!=')'){
			stk.push(c);
		}else{
			char top = stk.top();

			if(top == '('){
				return true;
			}

			while(stk.top()!='('){
				stk.pop();
			}
			stk.pop();
		}
	}

	return false;

}

int main(){

	int t;
	cin >> t;

	char ch[101]; 

	while(t--){
		cin >> ch;

		string s = redundant_parentheses(ch) ? "Duplicate" : "Not Duplicates";  

		cout << s << endl;
	}
	

	return 0;
}