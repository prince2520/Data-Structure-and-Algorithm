#include <iostream>
using namespace std;

#define INT_MAX 999999

int n = 4;

int dist[10][10] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

int VISITED_ALL = (1<<n) - 1;

int dp[(1<<4)][4+1];

int tsp(int mask, int pos){
	// Base case 
	if(VISITED_ALL == mask){
		return dist[pos][0];
	}

	int ans = INT_MAX;

	// Look up
	if(dp[mask][pos]!=-1)
		return dp[mask][pos];

	// Rec case 
	for(int city=0; city<n; city++){
		if((mask&(1<<city))==0){
			ans = min(ans, dist[pos][city] + tsp(mask|(1<<city), city));
		}
	}

	return dp[mask][pos] =  ans;
}

int main(){
	for(int i=0; i<VISITED_ALL+1; i++){
		for(int j=0; j<n; j++){
			dp[i][j] = -1;
		}
	}

	cout << tsp(1, 0) << endl;



	return 0;
}