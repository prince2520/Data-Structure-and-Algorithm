#include <iostream>
#include <algorithm>

using namespace std;

void displayTriplet(int arr[], int first_number, int start, int end, int remSum){
	int i = start;
	int j = end-1;

	while(i<j){
		int other_two_sum = arr[i] + arr[j];

		if(other_two_sum == remSum){
			cout << first_number <<", " << arr[i] << " and " << arr[j] << endl;
			i++;
		}else if(other_two_sum > remSum){
			j--;
		}else{
			i++;
		}
	}
}


void target_triplet_sum(int arr[1000], int n, int target){

	int i=0;

	while(i<n){
		int remSum = target-arr[i];

		displayTriplet(arr,  arr[i], i+1, n, remSum);

		i++;
	}
}


int main(){
	int n;
	cin >> n;

	int arr[1000]={0};

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int target;
	cin >> target; 

	sort(arr, arr+n);

	target_triplet_sum(arr, n, target);

	return 0;
}