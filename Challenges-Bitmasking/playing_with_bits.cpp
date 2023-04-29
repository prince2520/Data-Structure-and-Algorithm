#include <iostream>
using namespace std;

int countSetBits(int num){

	int count = 0;

	while(num > 0){
		count += (num & 1);

		num = num >> 1;  
	} 

	return count;

}


int playing_bits(int startNo, int endNo){

	int ans = 0;

	for(int i=startNo; i<=endNo; i++){
		ans += countSetBits(i);
	}

	return ans;

}

int main(){
	int q;
	cin >> q;

	for(int i=0; i<q; i++){

		int s=0, e=0;
		cin >> s >> e;

		cout << playing_bits(s, e) << endl;
	}


	return 0;
}