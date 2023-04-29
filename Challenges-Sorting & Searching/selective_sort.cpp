#include <iostream>
using namespace std;

void selective_sort(int arr[1000], int n){

	for(int i=0; i<n; i++){
		int index = i;
		
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[index]){
				index = j;
			}
		}
		
		swap(arr[i], arr[index]);

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

	selective_sort(arr, n);


	return 0;
}