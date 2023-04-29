#include <iostream>
using namespace std;

void wave_sort(int arr[], int n){


	for(int i=0; i<n; i=i+2){

		if(i!=(n-1) and arr[i+1]>arr[i]){
			swap(arr[i+1], arr[i]);
		} 

		if(i!=0 and  arr[i-1]>arr[i]){
			swap(arr[i-1], arr[i]);
		}

	}


}

int main(){

	int arr[] = {1, 3, 4, 2, 7, 4};
	int n = sizeof(arr) / sizeof(int);

	wave_sort(arr, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;
} 