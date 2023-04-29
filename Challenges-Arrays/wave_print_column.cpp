#include <iostream>
using namespace std;

void wave_print(int arr[10][10], int m, int n){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i%2==0){
				cout << arr[j][i] << ", ";
			}else{
				cout << arr[m-j-1][i] << ", ";
			}
		}
	}

	cout << "END";

}

int main(){
	int m, n;
	cin >> m >> n;

	int arr[10][10]; 

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	wave_print(arr, m, n);

	return 0;
}