#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayKSum(int *arr, int n, int k){

	unordered_map <int, int> m;

	int pre = 0;

	int len = 0;

	for(int i=0; i<n; i++){
		pre += arr[i];

		if(pre == k){
			len = max(len, k+1);
		}
		
		if(m.find(pre-k) != m.end()){
			len = max(len, i-m[pre-k]);
		}else{
			m[pre] = i;
		}

	}

	return len;

}

int main(){
	int n, k;
	cin >> n >> k;

	int arr[n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << longestSubarrayKSum(arr, n, k) << endl;

	return 0;
}