#include <iostream>

using namespace std;

int main(){
	int x = 10;
	int *xptr;

	xptr = &x;

	cout << &x << endl; // x address 
	cout << xptr << endl; // x address 

	cout << *(&x) << endl; // 10
	cout << *(xptr) << endl; // 10

	cout << *(&xptr) << endl; // x address 
	cout << &(*xptr) << endl; // x address 

	cout << &xptr << endl;

	int **xxptr = &xptr;
	cout << xxptr << endl;

	return 0;
}