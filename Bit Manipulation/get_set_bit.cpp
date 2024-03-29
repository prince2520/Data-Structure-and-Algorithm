#include <iostream>
using namespace std;

bool isOdd(int n){
	return n & 1;
}

int getBit(int n, int i){
	int mask = (1 << i);
	int bit  = (n & mask) > 0 ? 1 : 0;

	return bit;
}

int setBit(int n, int i){
	int mask = (1 << i);
	int ans = n | mask;

	return ans;
}

int main(){

	int n = 5;
	int i; 

	cin >> i;
	cout << getBit(n, i) << endl;

	n = setBit(n, i);
	cout << "Ans " << n << endl;


	//cout << isOdd(n) << endl;


	return 0;
}