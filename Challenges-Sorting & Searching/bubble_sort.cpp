#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int arr[1000], int n){

	for(int j=1; j<=n-1; j++){
		for(int i=0; i<n-j; i++){
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
			}	
		}
	}

	for( int i =0; i<n; i++){
		cout << arr[i] << endl;
	}	

}

int main(){
	int n;

	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	bubble_sort(arr, n);

	return 0;
}