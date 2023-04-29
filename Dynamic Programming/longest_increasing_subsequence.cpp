#include <iostream>
#include <vector>

using namespace std;

int longIncreasingSubsequence(int *arr, int n, int idx, int prevIdx, vector<vector<int>> &dp){
	// Base case
	if(idx == n){
		return 0;
	} 

	// Rec case 

	if(dp[idx][prevIdx+1] != -1){
		return dp[idx][prevIdx+1];
	}

	int len = 0;
	
	len = longIncreasingSubsequence(arr, n, idx+1, prevIdx, dp); // leave it 

	if(prevIdx == -1 or arr[prevIdx] < arr[idx]){
		len = max( len, 1 + longIncreasingSubsequence(arr, n, idx+1, idx, dp)); // take it
	}


	return dp[idx][prevIdx+1] = len;
}


int main(){

	int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

	int n = sizeof(arr) / sizeof (int);

	vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

	cout << longIncreasingSubsequence(arr, n, 0, -1, dp) << endl;

	return 0;
}