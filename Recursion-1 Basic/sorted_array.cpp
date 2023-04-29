#include <iostream>
using namespace std;

bool isSorted(int arr[], int n){

	// Base case 
	if( n == 0 or n == 1){
		return true;
	}

	//Rec case 
	if(arr[0] < arr[1] and isSorted(arr+1, n-1)){
		return true;
	}

	return false;
}

int main(){

	int arr[] = {1, 2, 13, 4, 5};

	int n = sizeof(arr) / sizeof(int);

	cout << isSorted(arr, n) << endl;

	return 0;
}