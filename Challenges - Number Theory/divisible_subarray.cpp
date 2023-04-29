#include <iostream>
using namespace std;

#define ll long long

int main(){
	
	int t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;

		int arr[1005] = {0};

		int pre[1005] = {0};

		ll sum = 0;

		pre[0] = 1;

		for(int i=0; i<n; i++){
			
			cin >> arr[i];

			sum += arr[i];

			sum %= n;

			sum = (sum + n) % n;

			pre[sum]++;

		}

		ll ans = 0;

		for(int i=0; i<n; i++){
			ll m = pre[i];
			ans += m * (m-1) / 2;
		}

		cout << ans << endl;
	}


	return 0;
}