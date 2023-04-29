#include <iostream>
#include <climits>
using namespace std;

#define ll long long

ll exchanging_coins(ll n){

	// Base case 
	if(n==0)
		return 0;

	// Rec case  

	int max_gold = n;

	int ans = exchanging_coins(n/2) + exchanging_coins(n/3) + exchanging_coins(n/4);

	max_gold = max(max_gold, ans);

	return max_gold;
}

int main(){
	ll n;
	cin >> n;

	cout << exchanging_coins(n) << endl;

	return 0;
}