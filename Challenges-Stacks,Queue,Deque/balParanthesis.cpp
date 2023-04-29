#include <iostream>
#include <stack>
using namespace std;

bool balancedParanthesis(char *s){
	stack<char> stk;


	for(int i=0; s[i]!='\0'; i++){

		if(s[i] == '{' || s[i] == '(' || s[i] == '[' ){
			stk.push(s[i]);
		}else{
			if(stk.empty()){
				return false;
			}

			char top = stk.top();

			switch(top){
				case '{':
				if(s[i]=='}'){
					stk.pop();
					break;
				}else{
					return false;
				}				
				case '(':
				if(s[i]==')'){
					stk.pop();
					break;
				}else{
					return false;
				}	
				case '[':
				if(s[i]==']'){
					stk.pop();
					break;
				}else{
					return false;
				}	
			}
		}
	}

	if(!stk.empty()){
		return false;
	}

	return true;

}

int main(){

	char s[100];
	cin >> s;

	if(balancedParanthesis(s)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl; 
	}

	return 0;
}