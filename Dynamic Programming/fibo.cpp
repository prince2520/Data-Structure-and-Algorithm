#include <iostream>
using namespace std;

// Top down approach 
int fiboTop(int n, int *dp){
	// Base case 

	if(n==0 or n==1){
		return n;
	}

	// Rec case 

	if(dp[n]!=0){
		return dp[n];
	}

	int ans = fiboTop(n-1, dp) + fiboTop(n-2, dp);

	dp[n] = ans;

	return ans;
}

// Bottom down approach 
int fiboBottom(int n){
	int dp[1000] = {0};

	dp[1] = 1;

	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

// Bottom down approach optimised
int fiboBottomOptimised(int n){
	int a = 0;
	int b = 1;

	int c;

	for(int i=2; i<=n; i++){
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int main(){
	int n;
	cin >> n;

	int dp[1000] = {0};

	// Top down approach 
	cout << fiboTop(n, dp) << endl;

	// Bottom top approach 
	cout << fiboBottom(n) << endl;

	// Bottom top optimised approach
	cout << fiboBottomOptimised(n) << endl;

	return 0;
}