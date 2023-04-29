#include <iostream>
#include <climits>

using namespace std;

int minimum_money(int n, int w,  int *prices, int *dp){
	// Base case 
	if(w==0){
		return 0;
	}

	// Look Up
	if(dp[w] != 0)
		return dp[w];

	// Rec case

	int min_amount = INT_MAX;

	for(int i=0; i<n; i++){
		int ithW = i+1;

		if(ithW>w)
			break;

		if(prices[i]==(-1))
			continue; 

		if(w-ithW>=0)
			min_amount = min(min_amount, prices[i] + minimum_money(n, w-ithW, prices, dp));
	}


	return dp[w] = min_amount;

}

int main(){
	int N, W;
	cin >> N >> W;

	int prices[W+1];

	for(int i=0; i<W; i++)
		cin >> prices[i];

	int dp[W+1] = {0};

	int ans =  minimum_money(W, W, prices, dp) ;

	cout << (ans < 0 ? -1 : ans)  << endl;

	return 0;
}