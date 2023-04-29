#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longIncreasingSubsequence(int *arr, int n){
	vector<int> temp;

	temp.push_back(arr[0]);

	for(int i=0; i<n; i++){
		if(arr[i] > temp.back()){
			temp.push_back(arr[i]);
		}else{

			int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			arr[idx] = arr[i];
		}

	}

	return temp.size();
}


int main(){

	int arr[] = {5, 4, 11, 1, 16, 18};

	int n = sizeof(arr) / sizeof (int);

	cout << longIncreasingSubsequence(arr, n) << endl;

	return 0;
}
