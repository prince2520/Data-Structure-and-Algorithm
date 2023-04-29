#include <iostream>
#include <algorithm>
using namespace std;


void sort_linear_time(int arr[1000], int n){

	int s = 0;
	int e = n-1;
	int mid = 1;

	while( mid <= e){
		if(arr[mid] == 0){
			swap(arr[mid], arr[s]);
			mid = mid + 1;
			s = s + 1;
		}else if(arr[mid] == 2){
			swap(arr[mid], arr[e]);
			e = e - 1;
		}else{
			mid = mid + 1;
		}
	}
}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	sort_linear_time(arr, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << endl;
	}


	return 0;
}