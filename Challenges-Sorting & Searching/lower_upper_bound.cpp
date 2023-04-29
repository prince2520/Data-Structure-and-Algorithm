#include <iostream>
using namespace std;

int lower_bound(int arr[100000], int n, int q){
	int i=0;
	int j=n-1;

	int lb = -1;

	while(i<=j){
		int mid = (i+j)/2;

		if(arr[mid] == q){
			lb = mid;
			j = mid - 1;
		}else if(arr[mid] < q){
			i = mid + 1;
		}else{
			j = mid - 1; 
		}
	}

	return lb;
}

int upper_bound(int arr[100000], int n, int q){
	int i=0;
	int j=n-1;

	int ub = -1;

	while(i<=j){
		int mid = (i+j)/2;

		if(arr[mid] == q){
			ub = mid;
			i = mid + 1;
		}else if(arr[mid] < q){
			i = mid + 1;
		}else{
			j = mid - 1; 
		}
	}

	return ub;
}

int main(){

	int n;
	cin >> n;

	int arr[100000];

	for(int j=0; j<n; j++){
		cin >> arr[j];
	}

	int q;
	cin >> q;

	int qArr[100];
	for(int k=0; k<q; k++){
		cin >> qArr[k];
	}

	for(int i=0; i<q; i++){
		cout << lower_bound(arr, n, qArr[i]) << " " << upper_bound(arr, n, qArr[i]) << endl;
	}

	return 0;
}