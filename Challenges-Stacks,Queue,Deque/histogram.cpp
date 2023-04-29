#include <iostream>
#include <stack>
using namespace std;

void prevSmaller(int *arr, int n, int *pSmall){
	stack <int> s;

	for(int i=0; i<n; i++){
		while(!s.empty() and arr[i]<=arr[s.top()]){
			s.pop();
		}

		if(s.empty()){
			pSmall[i] = -1;
		}else{
			pSmall[i] = s.top();
		}

		s.push(i);
	}

}

void nextSmaller(int *arr, int n, int *nSmall){
	stack <int> s;

	for(int i=n-1; i>=0; i--){
		while(!s.empty() and arr[i]<=arr[s.top()]){
			s.pop();
		}

		if(s.empty()){
			nSmall[i] = n;
		}else{
			nSmall[i] = s.top();
		}

		s.push(i);
	}
}

void histogram(int arr[], int n){

	int pSmall[n];
	int nSmall[n];

	prevSmaller(arr, n, pSmall);
	nextSmaller(arr, n, nSmall);

	int area = -1;
	for(int i=0; i<n; i++){
		area = max(area,  (nSmall[i] - pSmall[i] - 1) * arr[i] );
	}

	cout << area << endl;

}

int main(){
	int n;
	cin >> n;

	int arr[100];

	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	histogram(arr, n);

	return 0;
}