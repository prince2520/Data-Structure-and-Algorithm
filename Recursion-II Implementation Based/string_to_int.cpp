#include <iostream>
#include <cstring>
using namespace std;

int stringToInt(char arr[], int n){

	// Base case 
	if( n == 0 ){
		return 0;
	}

	// Rec case  
	int last_digit = arr[n-1] - '0';
	int smallAns = stringToInt(arr, n-1);

	return smallAns*10 + last_digit;
 }

int main(){
	char arr[] = "1234";
	int len = strlen(arr);

	cout << stringToInt(arr, len) << endl;


	return 0;
}