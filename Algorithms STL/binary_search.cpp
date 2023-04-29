#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
	int n = sizeof(arr)/sizeof(int);

	// Search in a sorted Array 
	int key;
	cin >> key; 

	bool present = binary_search(arr, arr+n, key);

	if(present){
		cout << "Present" << endl;
	}else{
		cout << "Absent" << endl; 
	}


	// Two more things 
	// Get the occurance of the element 
	// lower_bound(s, e, key) and upper_bound(s, e, key)

	auto lb = lower_bound(arr, arr+n, key);

	cout << "lower_bound: " << (lb-arr) << endl ; 

	auto ub = upper_bound(arr, arr+n, key);

	cout << "upper_bound: " << (ub-arr) << endl;


	cout << "Occurance of " << key << " is " << (ub-lb) << endl;




	return 0;
}