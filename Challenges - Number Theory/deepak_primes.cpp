#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int arr[100000005] = {0};
vector <int> posVal;

void prime_seive(int arr[]){

	arr[2] = 1;

	for(ll i = 3; i <= 100000000; i += 2){
		arr[i] = 1; 
	}

	for(ll i = 3; i <= 100000000; i +=2){
		if(arr[i] == 1){
			for(ll j = i*i; j <= 100000000; j += i){
				arr[j] = 0;
 			}
		}
	}

	arr[0] = arr[1] = 0;
}


int main(){


	int pos;
	cin >> pos;

	prime_seive(arr);

	posVal.push_back(0);

	for(ll i = 2; i <= 100000000; i++){
		if(arr[i] == 1){
			posVal.push_back(i);
		}
	}

	cout << posVal[pos];

	return 0;
}