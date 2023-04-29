#include <iostream>

using namespace std;

int first_occurance(int arr[], int n, int key){
	int i = 0;
	int j = n-1;

	int ans = -1;

	while(i<=j){
		int mid = (i + j)/2;

		if(arr[mid]  == key){
			ans = mid;
			j = mid - 1;
		}else if(arr[mid] > key){
			j = mid - 1;
		}else{
			i = mid + 1;
		}
	}

	return ans;
}

int last_occurance(int arr[], int n, int key){
	int i = 0;
	int j = n-1;

	int ans = -1;

	while(i<=j){
		int mid = (i + j)/2;

		if(arr[mid]  == key){
			ans = mid;
			i = mid + 1;
		}else if(arr[mid] > key){
			j = mid - 1;
		}else{
			i = mid + 1;
		}
	}

	return ans;
}

int main(){

	int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20};
	int n = sizeof(arr) / sizeof(int);
    
    int key;
    cin >> key;

    // first and last occurence of a key in sorted array 

    cout << first_occurance(arr, n, key) << endl;

    cout << last_occurance(arr, n, key) << endl;


	return 0;
}