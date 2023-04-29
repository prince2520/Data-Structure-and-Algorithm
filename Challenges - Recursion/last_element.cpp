#include <iostream>
using namespace std;

int last_element(int arr[], int n, int key){

	// Base case

	if(n==0){
		return -1;
	}

	// Rec case

	int idx = last_element(arr+1, n-1, key);

	if(idx == -1){
		if(arr[0] == key){
			return 0;
		}else{
			return -1;
		}
	}

	return idx + 1;
	
}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int key;
	cin >> key;

	cout << last_element(arr, n, key);
	

	return 0;
}