#include <iostream>

using namespace std;

void binary_search(int arr[], int n, int key){

	int i=0;
	int j=n-1;

	while(i<=j){
		int mid =  (i + j)/2;

		if(arr[mid] == key){
			cout << arr[mid] << " at index "<< mid << endl;
			break;
		}

	    if(arr[mid] > key){
		    j = mid - 1;
		}else{
			i = mid + 1;
		}
	}

}

int main(){
	int n;
	cin >> n;

	int arr[100];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int key;
	cin >> key;

	binary_search(arr, n, key);



	return 0;
}