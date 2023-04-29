#include <iostream>

using namespace std;


void print_spiral_anticlockwise(int arr[][10], int m, int n){
	int startRow = 0;
	int startCol = 0;

	int endRow = m-1;
	int endCol = n-1;

	while(startCol<=endCol && startRow <=endRow){
		
		for(int i=startRow; i<=endRow; i++){
			cout << arr[i][startCol]<< ", ";
		}
		startCol++;

		for(int i=startCol; i<=endCol; i++){
			cout << arr[endRow][i]<<", ";
		}
		endRow--;

		if(startCol<=endCol){
			for(int i=endRow;i>=startRow; i--){
				cout << arr[i][endCol]<< ", ";
			}
			endCol--;	
		}

		if(startRow<=endRow){
			for(int i=endCol; i>=startCol; i--){
				cout << arr[startRow][i] << ", ";
			}
			startRow++;
		}	
	}

	cout << "END";
}


int main(){
	int m, n;
	cin >> m >> n ;

	int arr[10][10];

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j]; 
		}
	}

	print_spiral_anticlockwise(arr , m , n);

	return 0;
}