#include <iostream>
using namespace std;

char keys[][10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};


void keyboard_codes(char num[], char out[], int i, int j, int &count){
	// Base case
	if(num[i] == '\0'){
		out[j] = '\0';
		cout << out << " ";

		count = count+1;
		return;
	}

	// Rec case 

	int digit = num[i] - '0';

	if(digit == 0){
		keyboard_codes(num, out, i+1, j, count);
	}

	for(int k=0; keys[digit][k] != '\0'; k++){
		out[j] = keys[digit][k];

		keyboard_codes(num, out, i+1, j+1, count);
	}
} 


int main(){

	char num[1000];
	cin >> num;


	char out[100];


	int count = 0;

	keyboard_codes(num, out, 0, 0, count);


	cout << endl;
	cout << count << endl;

	return 0;
}