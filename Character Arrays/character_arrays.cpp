#include <iostream>
using namespace std;

int main(){
	int b[] = {1, 2, 3};
	cout << b << endl;

	char a[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << a << endl;

	char s1[] = {'h', 'e', 'l', 'l', '0'};
	char s2[] = "hello";

	cout << s1 << " " << sizeof(s1) << endl;
	cout << s2 << " " << sizeof(s2) << endl;

	char s3[10] = "hello";
	char s4[10];
	cin >> s4;
	cout << s4 << endl;															 

	return 0;
}