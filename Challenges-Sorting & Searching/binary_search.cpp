#include <iostream>
using namespace std;

int binary_search(int nums[100], int n, int key){
	int i = 0;
	int j = n-1;

	while(i <= j){
		int mid = (i+j)/2;

		if(nums[mid] == key){
			return mid;
		}else if( nums[mid] < key){
			i = mid + 1;
		}else{
			j = mid - 1; 
		}
	}

	return -1;
}

int main(){
	int n;
	cin >> n;

	int nums[100];

	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	int key;
	cin >> key;

	cout << binary_search(nums, n, key)<< endl;

	return 0;
}