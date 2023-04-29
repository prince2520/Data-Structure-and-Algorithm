#include <iostream>
using namespace std;

void generate_parentheses(char out[], int n, int open, int close, int i){
	// Base case
	if(close == n){
		out[i] = '\0';
		cout << out << endl;
	}

	// Rec case

	if(close<open){
		out[i] = ')';
		generate_parentheses(out, n, open, close+1, i+1);
	}
	
	if(open<n){
		out[i] = '(';
		generate_parentheses(out, n, open+1, close, i+1);
	}
}

int main(){
	
	int n;
	cin >> n;

	char out[22];

	generate_parentheses(out, n, 0, 0, 0);

	return 0;
}