#include <iostream>
#include <vector>
using namespace std;

int optimal_game_strategy(int i, int j, int *coins, vector<vector<int>> &dp){
	// Base case 
	if(i>j)
		return 0;

	if(dp[i][j]!=0)
		return dp[i][j];

	// Rec case 
	int case1 = coins[i] + min(optimal_game_strategy(i+2, j, coins, dp), optimal_game_strategy(i+1, j-1, coins, dp));
	int case2 = coins[j] + min(optimal_game_strategy(i+1, j-1, coins, dp), optimal_game_strategy(i, j-2, coins, dp));

	return dp[i][j] = max(case1, case2);
}

int main(){
	int n;
	cin >> n;

	int coins[10000];

	for(int i=0; i<n; i++)
		cin >> coins[i];

	vector<vector<int>> dp(n+1,vector<int> (n, 0));

	cout << optimal_game_strategy(0, n-1, coins, dp);

	return 0;
}