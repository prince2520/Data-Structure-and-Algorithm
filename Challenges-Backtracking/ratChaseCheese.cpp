#include <iostream>
using namespace std;

bool ratChaseCheese(char maze[10][10], int out[10][10],int i, int j, int m, int n){
	// Base case 
	if(i==m && j==n){
		out[i][j] = 1;
		for(int row=0; row<=m; row++){
			for(int col=0; col<=n; col++){
				cout << out[row][col] << " ";
			}
			cout << endl;
		}
		return true;
	}

	// Rec case

	if(maze[i][j] == 'X'){
		return false;
	}

	if(i<0 || j<0 || i>m || j>n){
		return false;
	}

	out[i][j] = 1;

	bool right, down, up, left;

	down = ratChaseCheese(maze, out, i+1, j, m, n);
	

	if(!down){
		right = ratChaseCheese(maze, out, i, j+1, m, n);
	}

	if(!down and !right){
		up = ratChaseCheese(maze, out, i-1, j, m, n);
	}

	if(!down && !right && !up){
		left = ratChaseCheese(maze, out, i, j-1, m, n);
	}


	out[i][j] = 0;

	if(right || down || left || up){
		return true;
	}

	return false;
}

int main(){
	int m, n;
	cin >> m >> n;


	int out[10][10] = {0};

	char maze[10][10];

	int count = 0;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> maze[i][j];
		}
	}

	bool ans = ratChaseCheese(maze, out, 0, 0, m-1, n-1);

	if(ans==false){
		cout << "NO PATH FOUND" << endl;
	}

	return 0;
}