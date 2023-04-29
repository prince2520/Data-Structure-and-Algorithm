#include <iostream>
using namespace std;

int power(int a , int n){
	//Base case 
	if( n == 1 ){
		return a;
	}

	// Rec case 
	return a * power(a, n-1); 
}

int main(){

	int a, n;
	cin >> a >> n;

	cout << power(a, n) << endl;


	return 0;
}