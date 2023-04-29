#include <iostream>
using namespace std;

#define ll long long

void prime_seive(int arr[]){

	arr[2] = 1;

	for(ll i = 3; i <= 1000; i += 2){
		arr[i] = 1; 
	}

	for(ll i = 3; i <= 1000; i +=2){
		if(arr[i] == 1){
			for(ll j = i*i; j <= 50; j += i){
				arr[j] = 0;
 			}
		}
	}

	arr[0] = arr[1] = 0;
}

int main(){
	int arr[1000005] = {0};
	int cArr[1000005] = {0}

	prime_seive(arr);

	for(ll i=1; i<=1000; i++){
		cArr[i] = cArr[i-1] + arr[i];
	}

	int t;
	cin >> t;

	while(t--){
		int  num1, num2;

		cin >> num1 >> num2;
		
		cout << cArr[num2] - cArr[num1 - 1] << endl;
	}

	return 0;
}