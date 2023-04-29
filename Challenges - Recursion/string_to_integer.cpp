#include <iostream>
using namespace std;

int stringToInt(string s, int i){
	// Base case
	if(s[i]=='\0'){
		return 0 ;
	}

	// Rec case 

	int last_digit = s[i] - '0';

	int ans = stringToInt(s, i-1) ;

	return (ans * 10) + last_digit;

	
}

int main(){

	string s;
	cin >> s;

	int length = s.length();

	cout << stringToInt(s, length-1);	

	return 0;
}