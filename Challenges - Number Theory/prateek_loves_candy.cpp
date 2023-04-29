#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void prime_seive(int arr[1000000]){

	arr[2] = 1;

	for(ll i=3; i <= 1000000; i+=2){
		arr[i] = 1;
	}

	for(ll i=3; i <= 1000000; i+=2){
		if(arr[i] == 1){
			for(ll j = i * i; j <=1000000; j += i){
				arr[j] = 0;
			}
		}
	}

	arr[0] = arr[1] = 0;
}

int main(){
	int arr[1000005] = {0};

	vector <int> posVal;

	prime_seive(arr);

	for(ll i = 0; i <= 1000000; i++){
		if(arr[i] == 1){
			posVal.push_back(i);
		}
	}

	int t; 
	cin >> t;

	while(t--){
		int p;
		cin >> p;

		cout << posVal[p-1] << endl;
	}

	return 0;
}