#include <iostream>
#include <map>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	int *arr = new int[100000];

	map <int,int> m;

	for(int i=0; i<n; i++){
		cin >> arr[i];
		m.insert(make_pair(arr[i], i));
	}

	int currK = 0;

	if(n == k){
		for(int i = n; i>0; i++){
			cout << i << " ";
		}
		cout << endl;

		return 0;
	}


	for(int i=0; i<n; i++){

		if(k == currK){
			break;
		}

		if(arr[i] != (n-i)){
			int idx = m[n-i];
			m[arr[i]] = idx;
			swap(arr[i], arr[idx]);

			currK++;
		}
	}

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}


	return 0;
}