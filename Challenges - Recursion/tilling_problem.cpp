#include <iostream>
using namespace std;

bool tiling_problem(int n, int m, int tile, int &count){
	// Base case
	if(n==0 || m==0){
		count++;
		return true;
	}
	// Rec case

	// horizontally
	if(m >= tile){
		tiling_problem(n-1, m, tile, count);
	}	

	// vertically
	if(n >= tile){
		tiling_problem(n, m-1, tile, count);
	}

	return false;


}

int main(){
	int t;
	cin >> t;

	for(int i=0; i<t; i++){
		int n, m;
		cin >> n >> m; 

		int count = 0;

		tiling_problem(n, m, m, count);

		cout << count << endl;


	}	

	return 0;
}