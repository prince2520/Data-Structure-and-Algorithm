#include <iostream>
using namespace std;

int main() {

	char c[10][10];
	c[0][0] = 'A';

	char a[][10] = {{'a','b','c', '\0'}, {'d', 'e', 'f', '\0'}};
	char b[][10] = {"abc", "de", "fgh"};

	cout << a[1] << endl;
	cout << b[1] << endl;
	cout << c[0][0] << endl;

	return 0; 
}