#include <iostream>
#include <algorithm>

using namespace std;

void rotate_image(int arr[][1000], int n){	
	
	// Reverse row-wise
	for(int i=0; i<n; i++){
		reverse(arr[i], arr[i]+n);
	}

	// Swap
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j){
				swap(arr[i][j], arr[j][i]);
			}
		}
	}

	// Output
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j] << " " ;
		}
		cout << endl;
	}


}

int main(){
	int n;
	cin >> n;

	int arr[1000][1000] = {0};

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}

	rotate_image(arr, n);

	return 0; 
}