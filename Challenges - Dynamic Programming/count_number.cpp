#include <iostream>
using namespace std;

#define ll long long

ll count(int n, int last_digit, ll dp[91][2]){
	// Base case
	if(n == 0)
		return 1;

	// Look Up
	if(dp[n][last_digit]!=0)
		return dp[n][last_digit];

	// Rec case 
	ll ans =  0;

	if(last_digit == 0){
		ans = count(n-1, 0, dp) + count(n-1, 1, dp);
	}else{
		ans = count(n-1, 0, dp); 
	}

	return dp[n][last_digit] = ans;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		ll dp[91][2] = {0};

		cout << count(n, 0, dp) << endl;
	}



	return 0;
}
