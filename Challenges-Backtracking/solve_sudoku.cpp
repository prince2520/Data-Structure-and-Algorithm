#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int sudoku[][9], int i, int j, int n, int num){

	// vertically and horizontally
	for(int k=0; k<n; k++){
		if(sudoku[i][k] == num || sudoku[k][j] == num){
			return false;
		}
	}

	int rn = sqrt(n);
	int x = (i/rn)*rn;
	int y = (j/rn)*rn;

	// In the box

	for(int row=x; row<x+3; row++){
		for(int col=y; col<y+3; col++){
			if(sudoku[row][col] == num){
				return false;
			}
		}
	}

	return true;
}

bool solve_sudoku(int sudoku[][9], int i, int j, int n){

	// Base case
	if(i==n){
		for(int row=0; row<n; row++){
			for(int col=0; col<n; col++){
				cout << sudoku[row][col] << " ";
			}
			cout << endl;
		}

		return true;
	}


	// Rec case

	if(j==n){
		return solve_sudoku(sudoku, i+1, 0, n);
	}

	if(sudoku[i][j] != 0){
		return solve_sudoku(sudoku, i, j+1, n);
	}

	for(int num=1; num<=n; num++){
		if(canPlace(sudoku, i, j, n, num)){
			
			sudoku[i][j] = num;

			bool ans = solve_sudoku(sudoku, i, j+1, n);

			if(ans){
				return true;
			}
		}
	}

	sudoku[i][j] = 0;

	return false;
}

int main(){
	int n;
	cin >> n;

	int sudoku[9][9] = {0};

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> sudoku[i][j];
		}
	}


	solve_sudoku(sudoku, 0, 0, 9);
	


	return 0;
}