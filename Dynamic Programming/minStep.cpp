#include <iostream>
#include <climits>

using namespace std;


// Top down approach 
int minStep(int n, int *dp){
	// Base case 
	if(n==1){
		return 0;
	}

	// Rec case 
	if(dp[n]!=0){
		return dp[n];
	}

	int opt1, opt2, opt3;

	opt1 = opt2 = opt3 = INT_MAX;

	if(n%3==0)
		opt3 = minStep(n/3, dp);
	

	if(n%2==0)
		opt2 = minStep(n/2, dp);

	opt1 = minStep(n-1, dp);

	int ans = min(min(opt1,opt2), opt3) + 1;

	return dp[n] = ans;
}


// Bottom up approach 

int minStepBU(int n){
	int dp[100] = {0};

	for(int i=2; i<=n; i++){

		int opt1, opt2, opt3;

		opt1 = opt2 = opt3 = INT_MAX; 

		if(i%3 == 0)
			opt3 = dp[i/3];
		

		if(i%2 == 0)
			opt2 = dp[i/2];

		opt1 = dp[i-1];


		dp[i] = min(min(opt1, opt2), opt3) + 1;		
	}

	return dp[n];
}

int main(){
	int n;
	cin >> n;

	int dp[100] = {0};

	cout << minStepBU(n) << endl;

	return 0;
}
