#include <iostream>

using namespace std;

void length_max_bitcoin(int arr[1000], int n ){

	int max_bit=0;

	int inc[n]={1};
	int dec[n]={1};

	inc[0] = 1;
	dec[n-1] = 1;

	// Increasing order
	for(int j=1; j<n; j++){
		if(arr[j] >= arr[j-1]){
			inc[j] = inc[j-1] + 1;
		}else{
			inc[j] = 1;
		}
	}

	// Decreasing order
	for(int i=n-2; i>=0; i--){
		if(arr[i] >= arr[i+1]){
			dec[i] = dec[i+1] + 1;
		}else{
			dec[i] = 1;
		}
	}

	for(int i=0; i<n; i++){
		max_bit = max( inc[i] + dec[i] - 1, max_bit ); 
	}

	cout << max_bit << endl;
}

int main(){
	int test_case;
	cin >> test_case;

	int i=0;

	while(i<test_case){
		int n ;
		cin >> n;

		int arr[1000000];

		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		length_max_bitcoin(arr, n) ;

		i++;
	}

	return 0;
}