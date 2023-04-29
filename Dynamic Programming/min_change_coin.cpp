#include <iostream>
#include <climits>
using namespace std;

// Top Down approach 

int minCoins(int n, int *coins, int T, int *dp){
	// Base case 
	if(n == 0){
		return 0;
	}

	// Rec case 

	if(dp[n] != 0)
		return dp[n];

	int ans = INT_MAX;

	for(int i=0; i<T; i++){

		if(n-coins[i]>=0){
			int subProb = minCoins(n - coins[i], coins, T, dp);

			ans = min(ans, subProb+1);

		}
	}

	return dp[n] = ans;
}

// Bottom Down Approach 

int minCoinsBottom(int n, int *coins, int T){

	int dp[100] = {0};



	for(int i=1; i<=n; i++){

		int ans = INT_MAX;

		for(int j=0; j<T; j++){
			
			if(i-coins[j] >= 0){
				ans = min(ans, dp[i-coins[j]]);
			}
		}

		dp[i] = ans + 1;

	}

	return dp[n];
}

int main(){
	int n = 15;
	int coins[]= {1, 7, 10};

	int dp[100] = {0};

	cout << minCoinsBottom(n, coins, 3) << endl;


	return 0;
}