#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int test_case;

	cin >> test_case;

	for(int i=0; i<test_case; i++){

		int n;
		cin >> n;

		int arr[1000];

		for(int j=0; j<n; j++){
			cin >> arr[j]; 
		}

		int last_num = arr[n-1];

		int cum_sum = 0;
		int max_sum = 0;

		if( last_num > 0){
			cum_sum = last_num;
		    max_sum = last_num;
		}
		
		for(int k=0; k<n-1; k++){
			cum_sum = cum_sum + arr[k];

			if(cum_sum < 0){
				cum_sum = 0;
			} 

			max_sum = max(cum_sum, max_sum);
		}
		cout << max_sum ; 
	} 



	return 0;
}