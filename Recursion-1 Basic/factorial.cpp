#include <iostream>
using namespace std;

int fact(int n){

	// Base case 
	if(n == 0){
		return 1;
	}

	// Recursive case 

	return n * fact(n - 1);
}


int main(){
	int n;
	cin >> n;

	cout << fact(n) << endl;

	return 0;
}