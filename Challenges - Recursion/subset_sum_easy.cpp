#include <iostream>
using namespace std;

void subset_sum_easy(int arr[], int i, int sum, int n, int &count){
	// Base case 
	if(i==n){
		if(sum == 0){
			count++;
		}
		return;
	}

	// Rec case

	// Include
	sum += arr[i];
	subset_sum_easy(arr, i+1, sum, n, count);

	// Exclude
	sum -= arr[i];
	subset_sum_easy(arr, i+1, sum, n, count);
}

int main(){
	int t;
	cin >> t;	

	while(t--){

		int n;
		cin >>n;

		int arr[10] = {0};

		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		int count = 0;

		subset_sum_easy(arr, 0, 0, n, count);

		if(count>1){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}


	}

	return 0;
}