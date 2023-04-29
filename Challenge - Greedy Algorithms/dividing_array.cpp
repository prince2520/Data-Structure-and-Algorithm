#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define ll long long

bool compare(ll a, ll b){
	return a > b;
}

void divide_array(ll *arr, int n){

	// Minimum value
	ll min_val = 0;
	for(int i=1; i<n; i+=2){
		min_val += abs(arr[i-1]-arr[i]);
	}
	cout << min_val << " ";

	// Maxmimum value
	ll max_val = 0;
	int j = 0;
	int k = n/2;
	
	while(j < n/2 and k < n){
		max_val += abs(arr[j]-arr[k]);
		k++;
		j++;
	}
	cout << max_val << endl;

	return;

}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		ll arr[100000];
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		sort(arr, arr+n, compare);

		divide_array(arr, n);

	}



	return 0;
}