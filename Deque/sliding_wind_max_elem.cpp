#include <iostream>
#include <deque>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[100];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int k;
	cin >> k;


	deque <int> Q(k); 

	int i;
	for(i=0; i<k; i++){

		while(!Q.empty() and arr[i] > arr[Q.back()]){
			Q.pop_back();
		}

		Q.push_back(i);
	}

	for(;i<n;i++){
		cout << arr[Q.front()] << " ";
		
		// remove n-k element 
		while(!Q.empty() and Q.front() <= i-k){
			Q.pop_front();
		} 

	
		while(!Q.empty() and arr[i] > arr[Q.back()]){
			Q.pop_back();
		}

		Q.push_back(i);
	}

	cout << arr[Q.front()] << endl;
	

	return 0;
}