#include <iostream>

using namespace std;

int matrix_search(int arr[30][30], int m, int n, int search){

	int i=m-1;
	int j=0;

	while(i>=0 && j<=n-1){
		if( search > arr[i][j]){
			j++;
		}else if (search < arr[i][j]){
			i--;
		}else{
			return 1;
		}
	}

	return 0;
}

int main(){
	int m, n;
	cin >> m >> n;

	int arr[30][30];

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}

	int search;
	cin >> search;

	cout << matrix_search(arr, m, n, search) ;

	return 0;
}