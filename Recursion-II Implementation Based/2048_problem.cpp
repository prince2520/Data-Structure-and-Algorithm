#include <iostream>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printSpellings(int n){

	// Base Case 
	if(n == 0){
		return;
	}

	// Rec Case
	printSpellings(n/10);

	int digit = (n%10);
	cout << words[digit] << " ";

}

int main(){

	int n;
	cin >> n;

	printSpellings(n);


	return 0;
}