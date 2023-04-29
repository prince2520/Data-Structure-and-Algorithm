#include <iostream>
#include <algorithm>

using namespace std;

void rain_water_harvesting(int arr[1000000], int n){
	int right[n] = {0};
	int left[n] = {0};

	int save_water = 0;

	int max_left = 0; 
	int max_right = 0;

	int i = 0; 
	int j = n-1;

	while(i<n && j >=0){
		max_left = max(arr[i], max_left);
		left[i] =  max_left;

		max_right = max(arr[j], max_right);
		right[j] =  max_right;

		i++;
		j--;
	}

	// Calculation for save water 

	for(int k=0; k<n; k++){
		save_water += min(left[k], right[k]) - arr[k];
	}

	cout <<  save_water;
}

int main(){
	
	int n;
	cin >> n;

	int arr[1000000];

	int i=0;

	while(i<n){
		cin >> arr[i];
		i++;
	}

	rain_water_harvesting(arr, n);

	return 0;
}