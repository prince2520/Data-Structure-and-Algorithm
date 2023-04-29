#include <iostream>
using namespace std;

bool isSorted(int arr[], int n){

	// Base case 

	if(n == 0){
		return true;
	}

	// Rec case

	if(arr[0] > arr[1]){
		return false;
	}

	return isSorted(arr+1, n-1);
}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << boolalpha << isSorted(arr, n-1);


	

	return 0;
}