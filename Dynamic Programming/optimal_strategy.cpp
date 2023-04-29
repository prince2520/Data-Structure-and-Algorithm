#include <iostream>
using namespace std;

int optimal_game_strategy(int *arr, int i, int j, int dp[][100]){
	// Base case 
	if(i>j){
		return 0;
	}

	if(dp[i][j]!=0){
		return dp[i][j];
	}

	// Rec case 

	int case1 = arr[i] + min(optimal_game_strategy(arr, i+2, j, dp), optimal_game_strategy(arr, i+1, j-1, dp));
	int case2 = arr[j] + min(optimal_game_strategy(arr, i, j-2, dp), optimal_game_strategy(arr, i+1, j-1, dp));

	return dp[i][j] = max(case2, case1);

}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	int dp[100][100] = {0};

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << optimal_game_strategy(arr, 0, n-1, dp);

	return 0;
}