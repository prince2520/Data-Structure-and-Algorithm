#include <iostream>
using namespace std;

int help_rahul(int arr[], int n, int key){

	int i=0;
	int j=n-1;

	while(i<=j){
		int mid = (i+j)/2;

		if(arr[mid] == key){
			return mid ;
		} else if(arr[i] <= arr[mid]){
			if(arr[i] <= key and key <= arr[mid]){
				j = mid - 1;
			}else{
				i = mid + 1;
			}

		}else{
			if(arr[mid] <= key and key <= arr[j]){
				i = mid + 1;
			}else{
				j = mid - 1;
			}

		}
	}

	return -1;

}

int main(){
	int n;
	cin >> n;

	int arr[100000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int key;
	cin >> key;

	cout << help_rahul(arr, n, key) << endl;
 
	return 0;
}