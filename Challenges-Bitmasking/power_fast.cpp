#include <iostream>
using namespace std;

int power_fast(int a, int n){

	int ans = 1;

	while(n>0){
		int last_bit = (n & 1);

		if(last_bit > 0){
			ans = ans * a;
		}

		n = n >> 1;
		a = a*a;
	}

	return ans;
}

int main(){
	int a, n;
	cin >> a >>  n;

	cout << power_fast(a, n) << endl;

	return 0;
}