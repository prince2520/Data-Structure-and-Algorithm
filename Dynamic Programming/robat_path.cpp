#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000007

int numWay(int dp[][100], int r, int c){

	// Base case 
	for(int i=0; i<r; i++){
		if(dp[i][0] == -1)
			break;

		dp[i][0] = 1;
	}

	for(int i=0; i<c; i++){
		if(dp[0][i] == -1)
			break;

		dp[0][i] = 1;
	}

	for(int i=1; i<r; i++){
		for(int j=1; j<c; j++){
			if(dp[i][j]==-1)
				continue;

			if(dp[i-1][j] != -1)
				dp[i][j] = dp[i-1][j]%MOD;

			if(dp[i][j-1]!= -1)
				dp[i][j] += dp[i][j-1]%MOD;

		}
	}

	if(dp[r-1][c-1]==-1){
		return 0;
	}

	return dp[r-1][c-1];


}

int main(){

	int dp[100][100];

	memset(dp,0, sizeof(dp));

	int r, c, p;
	cin >> r >> c >> p;

	while(p--){
		int x, y;
		cin >> x >> y;

		dp[x-1][y-1] = -1;
	}

	cout << numWay(dp, r, c) << endl;


	return 0;
}