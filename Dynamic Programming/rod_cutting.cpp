#include <iostream>
#include <climits>
using namespace std;

int max_profit_dp(int *prices, int n, int *dp){

	// Base case

	if(n == 0){
		return 0;
	} 

	if(dp[n]!=0){
		return dp[n];
	}

	// Rec case 
	int ans = INT_MIN;
	int profit = 0;

	for(int i=0; i<n; i++){
		int cut = i+1;

		profit = prices[i] + max_profit_dp(prices, n-cut, dp);
	    ans = max(ans, profit);
		
	}

	return dp[n] = ans;

}


int max_profit_bottom_up(int *prices, int n){

	int dp[n+1] = {0};


	for(int i=1; i<=n; i++){

		int ans = INT_MIN;

		for(int  j = 0; j < i; j++){
			int cut = j + 1;

			int profit = prices[j] + dp[i-cut];

			ans = max(profit, ans);
		}

		dp[i] = ans;
	}

	for(int i=0; i<=n; i++){
		cout << dp[i] << " " ; 
	}

	cout  << endl;

	return dp[n];
}

int main(){

	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};

	int n = sizeof(prices ) / sizeof(int);

	int dp[100] = {0};

	cout << max_profit_bottom_up(prices, n) << endl;   

	return 0;
}