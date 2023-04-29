#include <iostream>
using namespace std;


int staircase_search(int a[100][100], int m, int n, int key){
	
	int i = 0, j = m - 1;

	while( i<m && j >= 0 ){
		if(a[i][j] == key){
			cout << key << " found at index"<< "[" << i <<", " << j << " ]" <<endl;
			return 1;
		}else if(a[i][j] < key){
			i++;
		}else{
			j--;
		}
	}

	cout << key << " not found " << endl;
	return -1;
}

int main(){
	int a[100][100] = {0};
	int m, n, key ;

	cin >> m >> n ;

	for(int row=0; row<m; row++){
		for(int col=0; col<n; col++){
			cin >> a[row][col];
		}
		cout << endl;
	}

	cin>> key;

	staircase_search(a, m, n, key);

	return 0;
}