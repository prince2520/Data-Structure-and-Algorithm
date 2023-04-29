#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;

	int ans = 0, no = 0;

	for(int i=0; i<n; i++){
		cin >> no;

		ans = ans ^ no;
	}

	cout << no << endl;

	return 0;
}