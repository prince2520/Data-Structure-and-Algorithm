#include <iostream>
using namespace std;

int all_submatrics_sum(int arr[][100], int m, int n){

	int sum = 0; 
	
	// Sum of all submatrics

	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){

			int top_left = (i+1)*(j+1);
			int bottom_right = (m-i)*(n-j);

			sum += arr[i][j]*top_left*bottom_right;
		}
	}

	return sum;
}

int main(){
	int arr[100][100];
	int m, n;

	cin >> m >> n;

	for(int i=0; i < m; i++ ){
		for(int j=0; j < n; j++ ){
			cin >> arr[i][j] ;
		}
	}
	
	cout << "Sum of all submatrics " << all_submatrics_sum(arr, m, n) << endl;

	return 0; 
}