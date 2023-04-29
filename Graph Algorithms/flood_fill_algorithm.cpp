#include <iostream>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void flood_fill(int i, int j, char mat[][20], int R, int C, char ch, char color){
	// Base case 
	if(i<0 or j<0 or i>=R or j>=C)
		return;

	// Boundary case 

	if(mat[i][j] != ch){
		return;
	}

	// Rec case 

	mat[i][j] = color;

	for(int k=0; k<4; k++){
		flood_fill(i+dx[k], j+dy[k], mat, R, C, ch, color);
	}
}

int main(){
	int R, C;
	cin >> R >> C;


	char mat[20][20];

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> mat[i][j];
		}
	}

	flood_fill(2, 3, mat, R, C, '.', 'r');

	cout << endl;

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}