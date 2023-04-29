#include <iostream>
#include <algorithm>
using namespace std;

int make_changes(int coins[], int n, int money){
	//upper_bound(coins, coins+n, money);

	int ans = 0;

	while(money > 0 ){
		
		int idx = upper_bound(coins, coins+n, money) - coins - 1 ;

		money = money-coins[idx];

		ans++;
	}

	return ans;

}

int main(){
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int n = sizeof(coins) / sizeof(int);

	int money;
	cin >> money;

	// make change 
	cout << make_changes(coins, n, money);



	return 0;
}