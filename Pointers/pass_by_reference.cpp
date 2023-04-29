#include <iostream>

using namespace std;

void increment(int *xptr){
	*xptr = *xptr + 1;

	cout << " Inside Function: " << *xptr << endl; 
}

int main(){

	int x=10;

	increment(&x);

	cout << " Inside Function: " << x << endl;

	return 0;
}