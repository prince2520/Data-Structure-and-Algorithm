#include <iostream>
using namespace std;

int balife(int *arr, int n){

	int ans = 0;
	int sum = 0; 

	for(int i=0; i<n; i++){
		sum += arr[i];
	} 

	if(sum%n != 0){
		return -1;
	} 

	sum = sum/n;


	int diff;

	for(int i=0;i<n; i++){
		diff+=(arr[i] - sum);

		ans = max(ans, max(diff, -diff));
	}

	return ans; 

}

int main(){
	int n;
	cin >> n;

	int *arr = new int[100000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << balife(arr, n);

	delete [] arr;

	return 0;
}