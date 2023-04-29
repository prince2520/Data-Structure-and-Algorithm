#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[100];

	int bits[64] = {0};

	for(int i=0; i<n; i++){
		cin >> arr[i];

		int num = arr[i];
		int j = 0;
		
		while(num > 0){
			bits[j] += (num&1);
			num = num >> 1;
			j++;
		}
	}

	int p = 1;
	int ans = 0;

	for(int i=0; i<64; i++){
		bits[i] = bits[i]%3;

		ans += p*(bits[i]);

		p  = p << 1;
	}

	cout << ans << endl;


	return 0;
}