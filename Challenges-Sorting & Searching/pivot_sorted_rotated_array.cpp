#include <iostream>
using namespace std;

int help_rahul(int arr[], int n){

	int i=0;
	int j=n-1;

	while(i<=j){
		int mid = (i+j)/2;

		if(i == (j-1)){
			return i;
		}

		if(arr[i] <= arr[mid]){
			i = mid;
		}else{
			j = mid;
		}
	}

	return -1;

}

int main(){
	int n;
	cin >> n;

	int arr[100];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << help_rahul(arr, n) << endl;
 
	return 0;
}