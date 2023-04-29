#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool lexicoComapare(string a, string b){
	return a > b;
}

void biggest_number(string arr[100], int m){
 	int i=0;

 	string sum = "";

 	while(i<m){
 		sum += arr[i];
 		i++;
 	}

 	cout << sum << endl;
 }

int main(){
	int t;
	cin >> t; 

	int i=0;

	while(i<t){
		int m;
		cin >> m;

		string arr[100];

		for(int i=0; i<m; i++){
			cin >> arr[i];
		}

		sort(arr, arr+m, lexicoComapare);

	    biggest_number(arr, m);

		i++;
	}

	return 0;
}