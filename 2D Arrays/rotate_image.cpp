#include <iostream>
#include <algorithm>

using namespace std;

void display(int a[100][100], int n){
	for(int row=0; row<n; row++){
		for(int col=0; col<n; col++){
			cout << a[row][col]<<" ";
		}
		cout << endl;
	}
}

void rotate(int a[100][100], int n){
	for(int row=0; row<n; row++){
		int startCol = 0;
		int endCol = n-1;
		
		while(startCol<endCol){
			swap(a[row][startCol], a[row][endCol]);
			startCol+=1;
			endCol-=1;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j){
				swap(a[i][j], a[j][i]);
			}
		}
	}
}

void rotate_stl(int a[100][100], int n){
	for(int i=0; i<n; i++){
		reverse(a[i],a[i]+n);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j){
				swap(a[i][j], a[j][i]);
			}
		}
	}
}

int main(){
	int a[100][100] = {0};
	int n;

	cin >> n;

	for(int row=0; row<n; row++){
		for(int col=0; col<n; col++){
			cin >> a[row][col];
		}
		cout << endl;
	}

	//rotate(a, n);
	rotate_stl(a, n);
	display(a, n);

	return 0;
}