#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int ans = 0;

	// Bitwise XOR Operator to solve

	for(int i=0; i<n; i++){
		int no;
		cin >> no;

		ans = ans ^ no;
	}

	cout << ans << endl;


	return 0;
}