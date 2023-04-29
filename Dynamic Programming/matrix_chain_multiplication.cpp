#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int matrix_chain_multiplication(int s, int e, int *arr, vector<vector<int>> &dp){

	// Base case 
	if(s == e){
		return 0;
	}

	if(dp[s][e] != -1)
		return dp[s][e];

	// Rec case 
	int mini = INT_MAX;

	for(int k = s; k < e; k++){
		int steps = (arr[s-1] * arr[k] * arr[e]) + matrix_chain_multiplication(s, k, arr, dp) + matrix_chain_multiplication(k+1, e, arr, dp);

		mini = min(steps, mini);
	}

	return dp[s][e] = mini;

}

int main(){
	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	vector<vector<int>> dp(n, vector<int>(n, -1));


	cout << matrix_chain_multiplication(1, n-1, arr, dp) << endl;



	return 0;
}