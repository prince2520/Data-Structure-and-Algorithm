#include <iostream>
using namespace std;

int main(){

	// Allocation + Deallocation = Complier

	int b[100]={};
	cout << sizeof(b) << endl;
	cout << b << endl;
	// here b cant be overwritten.

	// Dynamic Allocation (on the fly)
	int n;
	cin >> n;

	int *a = new int[n];
	cout << sizeof(a) << endl;
	cout << a << endl; // variable a that is created inside the static memory -> Overwritten
	// a = new char[30];

	// No change 
	for(int i=0; i<n; i++){
		cin >> a[i];

		cout << a[i] << " " ;
	}


	delete []a;



	return 0;
}