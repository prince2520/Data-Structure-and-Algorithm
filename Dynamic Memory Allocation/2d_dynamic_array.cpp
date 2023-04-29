#include <iostream>
using namespace std;

int main(){

	int **arr;

	int r, c;
	cin >> r >> c;

	arr = new int*[r];

	// Creating an array of row heads 
	for(int i=0; i<r; i++){
		arr[i] = new int[c];
	}

	int val = 1;

	// take input and print the elements
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			arr[i][j] = val;
			val++;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}