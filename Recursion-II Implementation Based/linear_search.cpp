#include <iostream>
using namespace std;

int storeOcc(int a[], int i , int n, int key, int out[], int j){
	// Base case
	if(i == n){
		return j;
	}

	// Rec case

	if(a[i] == key){
		out[j] = i;
		return storeOcc(a, i+1, n, key, out, j+1);

	}

	return storeOcc(a, i+1, n, key, out, j);

}

void allOcc(int a[], int i, int n, int key){
	if (i == n){
		return;
	}

	if(a[i] == key){
		cout << i <<  ","; 
	}

	allOcc(a, i+1, n, key);
}

int last_occurance(int a[], int n, int key){
	// Base case 
	if(n == 0){
		return -1;
	}

	// Rec case 
	int i = last_occurance( a+1, n-1, key);

	if( i == -1){
		if(a[0] == key){
			return 0;
		}else{
			return -1;
		}
	}
 
	return i+1;

}

int first_occurance(int a[], int n, int key){
	
	// Base case

	if (n == 0){
		return -1;
	}

	if (a[0]==key){
		return 0;
	}

	// Rec case
	int i = first_occurance( a+1, n-1, key);

	if( i == -1){
		return -1;
	}
 
	return i+1;
}

int linearSearch(int a[], int i, int n, int key){
	// base case
	if( i == n ){
		return -1;
	}

	if( a[i] == key ){
		return i;
	}

	// Rec case
	return linearSearch(a, i+1 , n , key);
}

int main(){
	int a[] = { 1, 2, 3, 7, 4, 5, 6, 7, 10 };
	int n = sizeof(a)/sizeof(int);

	int key = 7;

	cout << first_occurance(a, n, key) << endl;
	cout << last_occurance(a, n, key) << endl;

	allOcc(a, 0, n, key);
	cout << endl;

	int output[100];
	int cnt = storeOcc(a, 0, n, key, output, 0);

	cout << "Count " << cnt << endl;
	for(int k = 0; k < cnt; k++){
		cout << output[k] << endl;
	}

	return 0;
}