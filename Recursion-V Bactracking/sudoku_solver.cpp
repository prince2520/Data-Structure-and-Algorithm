#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int num){

	for(int x=0; x<n; x++){
		if(mat[x][j] == num || mat[i][x] == num){
			return false;
		}
	}

	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x=sx; x<sx+3; x++){
		for(int y=sy; y<sy+3; y++){
			if(mat[x][y]==num){
				return false;
			}
		}
	}

	return true;
}

bool solveSuodoku(int mat[][9], int i, int j, int n){
	// Base case 

	if(i==n){
		for(int x=0; x<n; x++){
			for(int y=0; y<n; y++){
				cout << mat[x][y] << " ";
			}

			cout << endl;
		}
		return true;
	}

	// Rec case
	if(j==n){
		return solveSuodoku(mat, i+1, 0, n);
	} 

	if(mat[i][j] != 0){
		return solveSuodoku(mat, i, j+1, n);
	}

	
	for(int num=1; num<=n; num++){

		if(canPlace(mat, i, j, n, num)){

			mat[i][j] = num;

			bool couldWeSolve = solveSuodoku(mat, i, j+1, n);

			if(couldWeSolve){
				return true;
			}
		}
	}

	mat[i][j] = 0;

	return false;
}

int main(){

	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3}, 
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6}, 
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	solveSuodoku(mat, 0, 0, 9);
	
	return 0;
}