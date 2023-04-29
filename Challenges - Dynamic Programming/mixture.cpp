#include <iostream>
#include <climits>
using namespace std;

int mix_res(int *mix, int s, int e){
	int ans = 0;
	for(int i=s; i<=e; i++){
		ans += mix[i];
		ans = ans%100;
	}

	return ans;
}

int mixtures(int s, int e, int *mix, int dp[][101]){
	// Base case 
	if(s==e){
		return 0;
	}

	// look up
	if(dp[s][e]!=0)
		return dp[s][e];


	// Rec case 
	int min_smoke = INT_MAX;

	for(int k=s; k<e; k++){

		int smoke = mix_res(mix, s, k)*mix_res(mix, k+1, e) + mixtures(s, k, mix, dp) + mixtures(k+1, e, mix, dp);

		min_smoke = min(smoke, min_smoke); 
	}


	return dp[s][e] = min_smoke;
}

int main(){
	int n;
	cin >> n;

	int mix[101];

	for(int i=0; i<n; i++)
		cin >> mix[i];

	int dp[101][101] = {0};

	cout << mixtures(0, n-1, mix, dp) << endl;


	return 0;
}