#include <iostream>
#include <unordered_map>

using namespace std;

bool checkSum(int *arr, int n){

	unordered_map<int, bool> s;



	int cumSum = 0;

	for(int i=0; i<n; i++){
		cumSum += arr[i];

		if(cumSum == 0 or s.find(cumSum) != s.end()){
			return true;
		}

		s.insert(make_pair(cumSum, true));
	}

	return false;
}

int main(){
	int n;
	cin >> n;

	int arr[n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	if(checkSum(arr, n)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}