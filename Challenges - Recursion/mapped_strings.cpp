#include <iostream>
using namespace std;

void mapped_strings(char num[], int i, char out[] , int j){
	// Base case 

	if( num[i] == '\0'){
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// Rec case 

	int firstDigit = num[i] - '0';

	char ch = 'A' + firstDigit - 1;

	out[j] = ch;


	if(firstDigit != 0){
		mapped_strings(num, i+1, out, j+1);
	}else{
		mapped_strings(num, i+1, out, j);
	}

	if(num[i+1] != '\0'){
		int secondDigit = num[i+1] - '0';

		int twoDigitNum = firstDigit*10 + secondDigit;

		if(twoDigitNum <= 26){
			ch = 'A' + twoDigitNum - 1;

			out[j] = ch;
		    
		    mapped_strings(num, i+2, out,  j+1);
		}
	}
}

int main(){
	char num[100];
	cin >> num;

	char out[100];


	mapped_strings(num, 0, out, 0);


	

	return 0;
} 