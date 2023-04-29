#include <iostream>
using namespace std;

int LCS(string s1, string s2, int i, int j, int dp[][100]){

	// Base case 
	if(s1[i] == '\0' or s2[j] == '\0'){
		return 0;
	}

	// Rec case 
	if(s1[i] == s2[j]){
		return dp[i][j] = (1 + LCS(s1, s2, i+1, j+1, dp));
	}

	int opt1 = LCS(s1, s2, i+1, j, dp);
	int opt2 = LCS(s1, s2, i, j+1, dp);


	return dp[i][j] = max(opt1, opt2);
}

int main(){

	string s1 = "ABCD";
	string s2 = "ABEDG";

	int dp[100][100] = {-1};

	cout << LCS(s1, s2, 0, 0, dp) << endl;

	return 0;
}