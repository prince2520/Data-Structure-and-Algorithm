#include <iostream>
#include <algorithm>
using namespace std;

int grand_temple(int n){

	int *x = new int[100000];
	int *y = new int[100000]; 

	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}

	sort(x, x+n);
	sort(y, y+n);


	int dx = -1;
	int dy = -1;

	for(int i=1; i<n; i++){
		dx = max(dx, x[i]-x[i-1]-1);
		dy = max(dy, y[i]-y[i-1]-1);
	}

	delete [] x;
	delete [] y;


	return dx*dy;
}

int main(){
	int n;
	cin >> n;

	cout << grand_temple(n) << endl;

	return 0;
}