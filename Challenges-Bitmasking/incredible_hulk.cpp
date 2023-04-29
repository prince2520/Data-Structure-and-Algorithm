#include <iostream>
using namespace std;

int incredible_hulk(int s){

	int steps = 0;

	while(s>0){
		steps += (s & 1);
		s = s >> 1;
	}

	return steps;
}

int main(){
	int t;
	cin >> t;

	int i = 0;

	while(i<t){
		int s;
		cin >> s;

		cout << incredible_hulk(s) << endl;

		i++;
	}

	return 0;
}