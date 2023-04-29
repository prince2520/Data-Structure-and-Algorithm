#include <iostream>
#include <cstring>
using namespace std;

#define ll long;

int a[100005], pre[100005];

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		memset(pre, 0, sizeof(pre));

		pre[0] = 1;

		int sum = 0;
		
		for(int i=0; i<n; i++){
			cin >> a[i];

			sum += a[i];

			sum %= n;

			sum = (sum + n) % n;

			pre[sum]++;
		}

		int ans = 0;

		for(int i = 0; i < n; i++){
			ll m = pre[i];
			ans += (m) * (m-1) / 2;
		}

		cout << ans << endl;
	}


	return 0;
}