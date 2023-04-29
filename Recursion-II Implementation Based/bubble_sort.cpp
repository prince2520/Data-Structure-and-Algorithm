#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){

	// Base case
	if( n == 1 ){
		return;
	}

	// Rec case 
	for(int j = 0; j < n-1; j++){
		if(arr[j] > arr[j+1]){
			swap(arr[j], arr[j+1]);
		}
	}

	bubble_sort(arr, n-1);
}


void bubble_sort_recursive(int arr[], int j,  int n){

	// Base case 
	if( n == 1) {
		return;
	}

	if( j == n-1 ){
		return bubble_sort_recursive(arr, 0, n-1);

	} 

	if(arr[j]>arr[j+1]){
		swap(arr[j], arr[j+1]);
	}

	bubble_sort_recursive( arr, j+1 , n);
	return;
}




int main(){
	int arr[] = {5, 4, 3, 1, 2};
	int n = 5;

	bubble_sort_recursive(arr,0, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}