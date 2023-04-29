#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int test_case;
	cin >> test_case; 

	for(int j=0; j<test_case;j++){
		int n;
		cin >> n;

		int arr[100000];

		cin >> arr[0];

		int lar_num = arr[0];  

		for(int i=1; i<n; i++){
			cin >> arr[i];

			lar_num =  max(lar_num, arr[i]);
		}
		if(lar_num > 0){
			int max_sum = 0;
		    int cum_sum = 0;
		    
		    for(int i=0; i<n; i++){
		    	cum_sum = cum_sum + arr[i];
		    
		    	if(cum_sum < 0){
		    		cum_sum = 0;
		    	}

		    	max_sum = max( max_sum, cum_sum );

		    }
		    cout <<  max_sum << endl;
		}else{
			cout << lar_num << endl;
		}
	}

	return 0;
}