#include <iostream>
#include <deque>
using namespace std;

void strongestFighter(int *arr, int n, int k){

	deque <int> d(k);


	int i;
	for(i=0; i<k; i++){
		while(!d.empty() and arr[i] > arr[d.back()]){
			d.pop_back();
		}

		d.push_back(i);
	}


	for(;i<n; i++){
		cout << arr[d.front()] << " ";

		while(!d.empty() and d.front() <= i-k){
			d.pop_front();
		}

		while(!d.empty() and arr[i] > arr[d.back()]){
			d.pop_back();
		}

		d.push_back(i);
	}

	cout << arr[d.front()] << endl;
}


int main(){
	int n;
	cin >> n;

	int *arr = new int[10000000]{-1};
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int k;
	cin >> k;

	strongestFighter(arr, n, k);

	delete [] arr;

	return 0;
}