#include <iostream>
#include <stack>
using namespace std;

#define ll long long

void nextGreater(ll *arr, int n, ll *nextBig){

	stack<ll> stk;


	for(int i=2*n-2; i>=0; i--){

		while(!stk.empty() and arr[i%n] >= arr[stk.top()]){
			stk.pop();
		}

		if( i < n){
			if(stk.empty()){
				nextBig[i] = -1;
			}else{
				nextBig[i] = arr[stk.top()];
			}
		}

		stk.push(i%n);		
	}
}

int main(){
	int n;
	cin >> n;

	ll *arr = new ll[1000000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	ll *nextBig = new ll[n+1];

	nextGreater(arr, n, nextBig);

	for(int i=0; i<n; i++){
		cout << nextBig[i] << " ";
	}

	delete [] arr;

	return 0;
}
