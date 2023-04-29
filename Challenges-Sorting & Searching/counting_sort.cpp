#include <iostream>
using namespace std;

void counting_sort(int nums[100], int n){
	int count[n] = {0};
	int new_nums[n-1] = {0};

	for(int i=0; i<n; i++){
		count[nums[i]] += 1;
	}

	int sum = 0;

	for(int i=0; i<n; i++){
		sum = sum + count[i]; 
		count[i] = sum;
	}

	for(int i=0; i<n; i++){
		int index = count[nums[i]] - 1;
		new_nums[index] = nums[i];
		count[nums[i]]--;
	}

	for(int i=0; i<n; i++){
		cout << new_nums[i] << " ";
	}

}

int main(){
	int n;
	cin >> n;

	int nums[100];
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	counting_sort(nums, n);

	return 0;
}