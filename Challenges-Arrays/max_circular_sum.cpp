#include <iostream>

using namespace std;


void max_sum_circular_subarray(int arr[1000], int n, int total_sum){

	int min_sum = 0, cum_sum = 0;
	int max_sum = 0, cum_sum_max = 0;


	for(int i=0; i<n; i++){
		cum_sum += arr[i];
		cum_sum_max += arr[i];

		if(cum_sum > 0){
			cum_sum = 0;
		}

		if(cum_sum_max < 0){
			cum_sum_max = 0;
		}


		min_sum = min(min_sum, cum_sum);
		max_sum = max(max_sum, cum_sum_max); 

	}

	cout << max(max_sum, total_sum - min_sum) << endl;
}

int main(){
	int test_case;
	cin >> test_case;

	int i=0;

	while(i<test_case){
		int n;
		cin >> n;

		int arr[1000] = {0}; 

		int total_sum = 0;

		for(int j=0; j<n; j++){
			cin >> arr[j];
			total_sum += arr[j];
		}

		max_sum_circular_subarray( arr, n, total_sum);

		i++;

	}


	return 0;
}