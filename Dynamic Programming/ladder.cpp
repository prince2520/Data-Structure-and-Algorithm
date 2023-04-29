#include <iostream>

using namespace std;

int ladder_topdown(int n, int k, int *dp){

	// Base case
	if(n == 0){
		return 1;
	}


	// Rec case 

	if(dp[n]!=0){
		return dp[n];
	}

	int ways = 0;

	for(int i=1; i<=k; i++){
		if(n-i>=0){
			ways += ladder_topdown(n-i, k, dp); 
		}		
	}


	return dp[n] = ways;
}

int ladder_bottomUp(int n, int k){
	int dp[100] = {0};

	dp[0] = 1;

	for(int i=1; i<=n; i++){

		for(int j=1; j<=k; j++){
			if(i-j >= 0)
				dp[i] += dp[i-j];
		}

	}

	return dp[n];
}

int ladder_bottomUp_optimised(int n, int k){
	int dp[100] = {0};

	dp[0] = dp[1] = 1;

	for(int i=2; i<=n; i++){
		dp[i] = 2*dp[i-1];

		if(i-k-1>=0){
			dp[i] -=  dp[i-k-1];
		}
	}

	return dp[n];
}



int main(){
	int n, k;
	cin >> n >> k;

	int dp[100] = {0};

	cout << ladder_bottomUp_optimised(n, k) << endl;

	return 0;
}