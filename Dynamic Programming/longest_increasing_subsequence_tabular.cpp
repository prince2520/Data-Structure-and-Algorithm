#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longIncreasingSubsequence(int *arr, int n){
	int dp[n+1];

	vector <int> hash(n);

	int maxi = -1;
	int last_index = 0;

	for(int i=0; i<n; i++){
		dp[i] = 1;
		
		hash[i] = i;

		for(int prev=0; prev<i; prev++){

			if(arr[i] > arr[prev] and dp[i] < (1+dp[prev])){
				
				dp[i] = 1 + dp[prev];
				
				hash[i] = prev;
			
			}

		}

		if(dp[i]>maxi){
			maxi = dp[i];
			last_index = i;
		}
	}

	vector <int > temp;
	temp.push_back(arr[last_index]);

	while(hash[last_index] != last_index){
		last_index = hash[last_index];
		temp.push_back(arr[last_index]);
	}

	reverse(temp.begin(), temp.end());

	for(auto it:temp)
		cout << it << " ";
	cout << endl;

	return maxi;
}


int main(){

	int arr[] = {5, 4, 11, 1, 16, 18};

	int n = sizeof(arr) / sizeof (int);

	cout << longIncreasingSubsequence(arr, n) << endl;

	return 0;
}