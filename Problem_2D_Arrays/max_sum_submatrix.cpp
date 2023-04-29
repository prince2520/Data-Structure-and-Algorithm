#include <iostream>
#include <algorithm>
using namespace std;


int max_sum_submatrix(int arr[][100], int m, int n){

	//Column wise sum
	for(int i=m; i>0; i--){
		for(int j=n; j>0; j--){
			arr[i][j] += arr[i][j-1];
		}
	}

	//Row wise sum 
	for(int i=n; i>0; i--){
		for(int j=m; j>0; j--){
			arr[j][i] += arr[j-1][i];
		}
	}

	int max_sum = 0;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			max_sum = max(arr[i][j], max_sum);
		}
	} 

	return max_sum;
}

int main(){
	int m, n;
	cin >> m >> n;

	int arr[100][100];

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j] ;
		}
	} 

	cout << " max sum of submatrix is " << max_sum_submatrix(arr, m, n) << endl;

	
	return 0;
}