#include <iostream>
using namespace std;

void printIndices(int arr[], int n, int i, int key){

	// Base case 

	if(i == n){
		return ;
	}


	// Rec case 
	if(arr[0] == key){
		cout << i << " "; 
	}

	printIndices(arr+1, n, i+1, key);

}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int key;
	cin >> key;

	printIndices(arr, n, 0, key);


	return 0;
}