#include <iostream>
using namespace std;

int minimum_cost(int cost[][100], int r, int c){
	int dp[100][100];

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			
			if(i==0 && j==0){
				dp[i][j] = cost[i][j];
				continue;
			}

			if(i==0){
				dp[i][j] = cost[i][j] + dp[i][j-1];
			}else if(j == 0){
				dp[i][j] = cost[i][j] + dp[i-1][j];
			}else{
				dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[r-1][c-1];
}

int main(){
	int r, c;
	cin >> r >> c;

	int cost[100][100];

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin >> cost[i][j];


	cout << minimum_cost(cost, r, c) << endl;

	return 0;	
}