#include <iostream>
#include <climits>
using namespace std;

int min_jump(int *arr, int s, int n, int *dp){
	// Base case
	if(s >= n){
		return 0;
	}

	if(arr[s] == 0){
		return INT_MAX;
	}

	if(dp[s] != 0){
		return dp[s];
	}

	// Rec case 
	int min_steps = INT_MAX;

	for(int i=1; i<=arr[s]; i++){
		int steps = 1;

		if(s+i > n)
			break;

		int ans =  min_jump(arr, s+i, n, dp);

		if(ans != INT_MAX){
			
			steps += ans;

			min_steps = min(steps, min_steps);
		}
		
	}

	return dp[s] = min_steps;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int arr[10001];

		for(int i=0; i<n; i++)
			cin >> arr[i];

		int dp[1000] = {0};

		cout << min_jump(arr, 0, n-1, dp) << endl;
	}

	return 0;
}