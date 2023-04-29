#include <iostream>
using namespace std;

int countSetBits(int num){

	int count = 0;

	while(num>0){
		num = num & (num-1);
		count++;

		num >> 1;
	}

	return count;
}

int main(){
	int n;
	cin >> n;

	int num = 0;

	for(int i=0; i<n; i++){
		cin >> num;

		cout << countSetBits( num ) << endl;

	}


	return 0;
}