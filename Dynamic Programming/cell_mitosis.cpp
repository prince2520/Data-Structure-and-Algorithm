#include <iostream>
using namespace std;

#define ll long long

int cell_mitosis(int n, int x, int y, int z){

	ll *dp = new ll[1000];

	dp[0] = 0;

	dp[1] = 0;


	for(int i=2; i<=n; i++){
		int opt1 = 0;
		int opt2 = 0;

		if(n%2!=0){
			opt1 = dp[i-1] + y;
			opt2 = dp[(i+1)/2] + x + z;

			dp[i] = min(opt1, opt2);
		}else{

			opt1 = dp[i/2] + x;
			opt2 = dp[i-1] + y;

			dp[i] = min(opt1, opt2);
		}
	}

	return dp[n];
}

int main(){
	int n;
	cin >> n;

	int x, y, z;
	cin >> x >> y >> z;

	cout << cell_mitosis(n, x, y, z) << endl;

	return 0;
}