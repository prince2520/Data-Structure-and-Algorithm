#include <iostream>
using namespace std;

int main(){
	int x = 10;
	int y1 = 16;

	cout << &x << endl;

	float y = 10.5;
	cout << &y << endl;

	// It doesn't work for character variables 
	char ch = 'A';
	cout << &ch << endl;

	// Explicit typecasting from char* to void*
	cout << (void *)&ch << endl;

	// Pointers

	int *xptr;
	xptr = &x;

	cout << &x << endl;
	cout << xptr << endl;

	//Re-assign another address to the variable
	xptr =  &y1;

	cout << &y1 << endl;
	cout << xptr << endl;



	return 0;
}