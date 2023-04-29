#include <iostream>
using namespace std;

int clearBit (int n, int i){
	int mask = ~(1 << i) ;

	return (n & mask); 
}

int updateBit (int n, int i, int v){
	int mask = ~(1 << i);
	int cleared_n = n & mask;


	return cleared_n | (v << i);
}

int main(){

	int n = 5;
	int i;

	//cin >> i;
	//cout << clearBit(n, i) << endl;

	cout << updateBit(n, 2, 0) << endl;
	cout << updateBit(n, 3, 1) << endl; 




	return 0;
}