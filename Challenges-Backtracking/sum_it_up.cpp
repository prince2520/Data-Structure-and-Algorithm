#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sum_it_up(int arr[], int n, int target, int i, vector<int> &v){
	// Base case
	if(target == 0){

		for(auto val : v){
			cout << val << " ";
		}

		cout << endl;

		return true;
	}

	// Rec case 

	if(target<0){
		return false;
	}

	for(int k=i; k<n; k++){
			v.push_back(arr[k]);
 	        sum_it_up(arr, n, target-arr[k], k+1, v);
            v.pop_back();
		
	}

	return false;

}

int main(){
	int n;
	cin >> n;

	int arr[n+1];

	vector<int> v;

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int target;
	cin >> target;

	sort(arr, arr+n);

	sum_it_up(arr, n, target, 0, v);
	

	return 0;
}