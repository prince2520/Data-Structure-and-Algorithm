#include <iostream>
#include <math.h>
using namespace std;

int kth_root(long long  nums, long long power){

	int i = 0;
	int j = nums/2;
	int ans = 1;

	while(i<=j){
		int mid = (i+j)/2;

		if(power == 1){
			return nums;
		}

		if(pow(mid, power) <= nums){
			ans = mid;
			i = mid + 1; 
		}else{
			j = mid - 1;

		}

	}

	return ans;


}

int main(){

	int test_case;
	cin >> test_case;

	for(int i=0; i<test_case; i++){
		long long nums , power;
		cin >> nums >> power;

		cout << kth_root(nums, power) << endl;
	}


	return 0;
}