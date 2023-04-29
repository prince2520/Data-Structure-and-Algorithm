#include <iostream>
using namespace std;

int merge(int arr[], int s, int e){

	int mid = (s+e)/2;

	int i = s;
	int j = mid+1;
	int k = s;

	int temp[100];

	int cnt = 0;

	while(i <= mid and j <= e){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			cnt += mid - i + 1 ;
		}
	}

	while(i <= mid){
		temp[k++] = arr[i++];
	}

	while(j <= e){
		temp[k++] = arr[j++];
	}


	for(int i=s; i <= e; i++){
		arr[i] = temp[i];
	}


	return cnt;



}

int inversion_count(int arr[], int s, int e){
	// Base case
	if(s>=e){
		return 0;
	}

	// Rec case
	int mid = (s+e)/2;
	
	int x = inversion_count(arr, s, mid);
	int y = inversion_count(arr, mid+1, e);

	int z = merge(arr, s, e );

	return x + y + z ;
}

int main(){
	int arr[] = { 2, 4, 1, 3, 5};
	int n = sizeof(arr)/sizeof(int);

	cout << inversion_count(arr, 0, n-1); 


	return 0;
}