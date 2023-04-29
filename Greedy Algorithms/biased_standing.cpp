#include <iostream>
#include <cstring>
using namespace std;


int main(){
	int t;
	cin >> t;

	int arr[10000] = {0};

	while(t--){
		memset(arr, 0, sizeof( arr));

		string name;
		int n, rank;
		cin >> n;
			
		for(int i=1; i<=n; i++){
			cin >> name >> rank;
			arr[rank] ++;
		}

		int actual_rank = 1;
		int sum = 0; 

		for(int i=1; i<=n; i++){
			while(arr[i]>0){
				sum += abs(actual_rank-i);
				arr[i]--;
				actual_rank++;
			}
		}

		cout << sum  << endl;


	}



	return 0;
}