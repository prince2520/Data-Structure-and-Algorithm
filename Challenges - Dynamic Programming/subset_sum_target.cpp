#include <iostream>
#include <vector>
using namespace std;

bool target_sum(int s, int sum, int n,  int *arr, vector<vector<int>> &dp){
	// Base case 
	if(sum == 0){
		return true;
	}

	if(s==n){
		return false;
	}

	if(dp[s][sum]!=1){
		if(dp[s][sum] == 2)
			return true;
		else
			return false;
	}

	// Rec case 
	bool case1, case2;
	case1 = case2  = false;

	if(sum-arr[s] >= 0)
		 case1 = target_sum(s+1, sum-arr[s], n, arr, dp);
	
	 case2 = target_sum(s+1, sum, n, arr, dp);

	if(case1 || case2){
		dp[s][sum] = 2; 
		return  true;
	}
	else{
		dp[s][sum] = 3;
		return  false;
	}
 }

int main(){
	int n, sum;
	cin >> n >> sum;

	int arr[1000];

	for(int i=0; i<n; i++)
		cin >> arr[i];

	vector<vector<int>> dp(n+1, vector<int> (sum+1, 1));


	cout << (target_sum(0, sum, n, arr, dp) ? "Yes" : "No" )<< endl;

	return 0;
}