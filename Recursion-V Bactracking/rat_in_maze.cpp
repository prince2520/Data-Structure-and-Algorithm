#include <iostream>
using namespace std;

bool ratInMaze(char maze[][10], int soln[][10], int i, int  j, int  m, int  n){

	// Base case 

	if(i == m && j == n){

		soln[i][j] = 1;

		for(int i=0; i<=m; i++){
			for(int j=0; j<=n; j++){
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;

		return false;
	}

	if(maze[i][j] == 'X'){
		return false;
	}

	if( i>m || j>n ){
		return false;
	}

	// Rec case 

	soln[i][j] = 1;

	bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n);  
	bool leftSuccess = ratInMaze(maze, soln, i+1, j, m, n);

	soln[i][j] = 0;
 
	if( rightSuccess || leftSuccess ){
		return true;
	}

	return false;

}

int main(){
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	int soln[10][10] = {0};
	int m = 4, n = 4;


	bool ans = ratInMaze(maze, soln, 0, 0, m-1, n-1);

	if(ans==false){
		cout << "Path doesn't exist!";
	}


	return 0;
}