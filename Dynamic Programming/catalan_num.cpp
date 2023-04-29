#include <iostream>
using namespace std;

long long catalan_number(int n, long long *dp){
	dp[0] = dp[1] = 1;

	for(int i=2; i<=n; i++){
		dp[i] = 0;
		for(int j=1; j<=i; j++){
			dp[i] += dp[j-1]*dp[i-j];
		}
	}

	return dp[n];
}


 
int main(){
	int n;
	cin >> n;

	long long dp[100] ;

	cout << catalan_number(n, dp) << endl;



	return 0;
}
