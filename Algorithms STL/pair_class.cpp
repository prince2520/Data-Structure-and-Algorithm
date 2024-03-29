#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	pair <int, char> p;
	p.first = 10;
	p.second = 'B';

	// Another way 
	pair <int, char> p2(p);

	cout << p2.first << endl;
	cout << p2.second << endl;

	pair <int, string> p3 = make_pair(100, "Audi");
	cout << p3.first << " " << p3.second << endl;

	// Take input
	int a, b;
	cin >> a >> b;

	pair <int, int> p4 = make_pair(a, b);

	pair<pair<int,int>, string> car;
	
	car.second = "Audi";
	car.first.first = 10;
	car.first.second = 30;


	cout << car.first.first << endl;
	cout << car.second << endl;
	cout << "Hello";



	return 0;
}