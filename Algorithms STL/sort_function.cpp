#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a>b;
}

int main(){

	int n, key;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	// Sort an array using sort() function

	sort(arr, arr+n, compare);


	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}