#include <iostream>
#include <climits>
using namespace std;

int knapsack(int *wt, int *val, int cap, int n, int *dp){
	// Base case
	if(cap == 0){
		return 0;
	} 

	// Look Up
	if(dp[cap]!=0){
		return dp[cap];
	}

	// Rec case 
	int max_val = INT_MIN;

	for(int i=0; i<n; i++){

		int amount = 0;

		if(cap-wt[i]>=0){
			amount = val[i] + knapsack(wt, val, cap-wt[i], n, dp);

			max_val = max(max_val, amount);
		}

	}

	return dp[cap] = max_val;
}

int main(){
	int n, cap;
	cin >> n >> cap;

	int *wt = new int[100000];
	int *val = new int[100000];

	for(int i=0; i<n; i++)
		cin >> wt[i];

	for(int i=0; i<n; i++)
		cin >> val[i];

	int *dp = new int[100000]{0};

	cout << knapsack(wt, val, cap, n, dp) << endl;

	delete [] wt;
	delete [] val;
	return 0;
}