#include <iostream>
using namespace std;

void charater_type(char ch){
	if('A'<=ch && ch <= 'Z'){
		cout << 'U' << endl;
	}else if('a'<=ch && ch<='z'){
		cout << 'L' << endl;
	}else{
		cout << 'I' << endl; 
	}
}


int main(){
	char ch;
	cin >> ch;

	charater_type(ch);

	return 0;
}