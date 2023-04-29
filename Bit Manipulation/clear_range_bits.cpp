#include <iostream>
using namespace std;

int clearLastIBits(int n, int i){
	int mask = (-1 << i);
	return n & mask;
}

int clearRangeItoJ(int n, int i, int j){
	int ones = -1;
	int a = ones << (j+1);
	int b = (1 << i) - 1;
	int mask = a | b;
	int ans = n&mask;

	return ans; 
}

int main(){
	int n = 31;
	int i = 2, j = 3;

	//cout << clearLastIBits(n ,i) << endl;
	cout << clearRangeItoJ(n, i, j) << endl;

	return 0;
}