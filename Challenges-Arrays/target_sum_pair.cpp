#include <iostream>
#include <algorithm>

using namespace std;

void target_sum_pair(int arr[1000], int n, int target){
	int i=0;
	int j=n-1;
	
	while(i<j){
		int sum = arr[i] + arr[j]; 
		
		if( sum == target ){
			cout << arr[i] << " and " << arr[j] << endl;
			i++;
		}else if( sum > target ){
			j--;
		}else{
			i++;
		}
	}
}

int main(){
	int n ;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int target;
	cin >> target; 

	sort(arr, arr+n);

	target_sum_pair(arr, n, target);

	return 0;
}