#include <iostream>
using namespace std;

int main(){
	int N;

	cin >> N; 

	int arr[N];

	cin >> arr[0]; 

	int maxVal = arr[0];

	for(int i=1; i<N; i++){
		cin >> arr[i];

		if(maxVal<arr[i]){
			maxVal = arr[i];
		} 
	}

	cout << maxVal;

	return 0;
}