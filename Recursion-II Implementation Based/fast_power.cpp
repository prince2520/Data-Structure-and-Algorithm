#include <iostream>
using namespace std;

int power(int a, int n){
	if(n==1){
		return a;
	}

	return a * power(a, n-1);
}

int fast_power(int a, int n){
	
	// Base case

	if(n == 0){
		return 1;
	}

	// Rec case 

	int smaller_ans = fast_power(a, n/2);
	smaller_ans *= smaller_ans;

	if(n&1){
		smaller_ans = a * smaller_ans;
	}

	return smaller_ans;

}

int main(){
	int a, n;
	cin >> a >> n;

	cout << power( a, n ) << endl;
	cout << fast_power(a, n) << endl;



	return 0;
}