#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Knapsack_O_1(int i, int s, int n, int *items, int *prices, vector<vector<int>> &dp){
	
    // Base case 
	if(s<=0 or i==n){
		return 0;
	}

    // Memoziation
    if(dp[i][s]!=0){
        return dp[i][s];
    }

	// Rec case 
	int case1 = INT_MIN;
	int case2 = INT_MIN;

	if(s-items[i]>=0){
		case1 = prices[i] + Knapsack_O_1(i+1, s-items[i], n, items, prices, dp);
	}
	
	case2 = Knapsack_O_1(i+1, s, n, items, prices, dp);

	return  dp[i][s] = max(case1, case2);

}

int main(){
	// N-> Items 
	// S-> Bag capacity 
	
	int N, S;
	cin >> N >> S;

	int items[1000], prices[1000];
	
	for(int i=0; i<N; i++)
		cin >> items[i];

	for(int i=0; i<N; i++)
		cin >> prices[i];

    vector<vector<int>> dp(N+1, vector<int> (S+1, 0)); 
	
	cout << Knapsack_O_1(0, S, N, items, prices, dp) << endl;

	return 0;
}