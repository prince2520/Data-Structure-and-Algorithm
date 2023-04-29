#include <iostream>
using namespace std;

void smart_keypad(string table[], char num[], char out[], int i, int j){
	
	// Base case
	if(num[i] == '\0'){
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// Rec case
	int digit = num[i] - '0';

	for(int k=0; table[digit][k]!='\0'; k++){
		out[j] = table[digit][k];
		smart_keypad(table, num, out, i+1 ,j+1);
	}
}

int main(){
	string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

	char num[10];
	cin >> num;

	char out[20];

	smart_keypad(table, num, out, 0, 0 );

	return 0;
}