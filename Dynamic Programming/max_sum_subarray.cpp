#include <iostream>
using namespace std;

int maxSum(int *arr, int n){

	int dp[n+1] = {0};

	dp[0] = arr[0]>0?arr[0]:0;

	int max_sum = dp[0];
	for(int i=1; i<n; i++){
		dp[i] = dp[i-1] + arr[i];

		if(dp<0){
			dp[i] = 0;
		}

		max_sum = max(max_sum, dp[i]);
	}

	return max_sum;
}


int max_sum_optimised(int *arr, int n){

	int max_sum = 0;
	int currentSum = 0;

	for(int i=0; i<n; i++){
		currentSum += arr[i];

		if(currentSum < 0){
			currentSum = 0;
		}

		max_sum = max(currentSum, max_sum);

	}

	return max_sum;
}

int main(){
	
	int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};

	int n = sizeof(arr) / sizeof(int);

	cout << max_sum_optimised(arr, n) << endl;

	return 0;
}