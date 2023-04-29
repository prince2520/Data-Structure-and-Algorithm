#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){

	int i=s-1;
	int j=s;

	for(; j<=e-1; ){
		if(arr[j] <= arr[e]){
			i = i+1;
			swap(arr[j], arr[i]);
		}
		j = j+1;
	}


	swap(arr[i+1], arr[e]);

	return i+1;
}

void quicksort(int arr[], int s, int e){

	// Base Case
	if(s>=e){
		return;
	}

	// Recursive Case
	int p = partition(arr, s, e);

	quicksort(arr, s, p-1);
	quicksort(arr, p+1, e);

}

int main(){
	int arr[] = {2, 7, 8, 6, 1, 5,4};
	int n = sizeof(arr) / sizeof(int);

	quicksort(arr, 0, n-1);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}