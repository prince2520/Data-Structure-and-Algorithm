#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){
	
	int pivotElem = arr[e];

	int i = s-1;

	for(int j=s; j<=e-1 ;j++){
		if(arr[j]<=pivotElem){
			i = i + 1;
			swap(arr[j], arr[i]);
		}
	}

	swap(arr[i+1], arr[e]);


	return i+1;
}

void quicksort(int arr[], int s, int e){

	// Base case 
	if(s>=e){
		return;
	}

	// Rec case

	int p = partition(arr, s, e);

	quicksort(arr, s, p-1);
	quicksort(arr, p+1, e);
}

int main(){
	int n;
	cin >> n;

	int arr[n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	quicksort(arr, 0, n-1);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	

	return 0;
}	