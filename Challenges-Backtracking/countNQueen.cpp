#include <iostream>
using namespace std;

bool canPlace(int chess[11][11], int i, int j, int n){

	// Right diagonal
	int row = i;
	int col = j;

	while(col<n and row >= 0){
		if(chess[row][col] == 1){
			return false;
		}

		row--;
		col++;
	}


	// Left diagonal
	row = i;
	col = j;

	while(col>=0 and row >=0){

		if(chess[row][col] == 1){
			return false;
		}

		row--;
		col--;

	}

	// Up
	for(int k=0; k<=i; k++){
		if(chess[k][j] == 1){
			return false;
		}
	}


	return true;

}

void countNQueen(int chess[11][11], int i, int n, int &count){
	// Base case
	if(i == n){
		count++;
		return;
	}

	// Rec case
	for(int j=0; j<n; j++){
		if(canPlace(chess, i, j, n)){
			chess[i][j] = 1;
			countNQueen(chess, i+1, n, count);
			chess[i][j] = 0;
		}
	} 
}


int main(){

	int n;
	cin >> n;

	int chess[11][11] = {0};

	int count = 0; 

	countNQueen(chess, 0, n, count);

	cout << count << endl;

	return 0;
}