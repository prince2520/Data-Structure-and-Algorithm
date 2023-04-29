#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){

	// Check Column
	for(int row=0; row<i; row++){
		if(board[row][j] == 1){
			return false;
		}
	}

	// Check left diagonal

	int x = i;
	int y = j;

	while(x>=0 && y>=0){
		if(board[x][y] == 1){
			return false;
		} 
		x--;
		y--;
	}

	// Check right diagonal
	x = i;
	y = j;

	while(x>=0 && y<n){
		if(board[x][y] == 1){
			return false;
		} 
		x--;
		y++;
	}

	return true;


}

bool solveNQueen(int board[][10], int i, int n){
	// Base case
	if(i == n){
		for(int row=0; row<n; row++){
			for(int col=0; col<n; col++){
				if(board[row][col] == 0){
					cout << "_ "; 
				}else{
					cout << "Q ";
				}
			}
			cout << endl;
		}

		cout << endl <<endl;
		return true;
	}
	// Rec case
	for(int j=0; j<n; j++){

		if(isSafe(board, i, j, n)){
			board[i][j] = 1;
			bool nextQueenRakhPaye = solveNQueen(board, i+1, n);

			if(nextQueenRakhPaye){
				return true;
			}

			board[i][j] = 0;
		}

	}

	return false;
}

int main(){
	int n;
	cin >> n;

	int board[10][10] = {0};

	solveNQueen(board, 0, n);
	

	return 0;
}