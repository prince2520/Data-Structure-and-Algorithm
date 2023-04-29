#include <iostream>
using namespace std;

bool isPalindrome(int arr[1000], int n){
	int i=0;
	int j=n-1;

	while(i<j){

		if(arr[i]-arr[j]!=0){
			return false;
		}

		i++;
		j--;
	}

	return true;

}

int main(){
	int n;
	cin >> n;

	int arr[1000];

	for(int i=0; i<n; i++){
		cin >> arr[i]; 
	}

	cout << boolalpha ;


	cout << isPalindrome(arr, n);
	return 0;
}