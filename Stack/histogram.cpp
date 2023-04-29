#include <iostream>
#include <stack>
using namespace std;

void prevSmaller(int *arr, int *pSmall, int n){
	stack <int> s;

	for(int i=0; i<n; i++){
		while(!s.empty() and arr[s.top()] >= arr[i]){
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

void nextSmaller(int *arr, int *nSmall, int n){
	stack <int> s;

	for(int i=n-1; i>=0; i--){
		while(!s.empty() and arr[s.top()] >= arr[i]){
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

void histogram(int *arr, int n){

	int pSmall[n+1];
	int nSmall[n+1];

	prevSmaller(arr, pSmall, n);
	nextSmaller(arr, nSmall, n);

	int area = -1;
	
	for(int i=0; i<n; i++){
		
		int nArea;

		nArea = (nSmall[i] - pSmall[i] - 1) * arr[i];
		area = max(area, nArea);
	}

	cout << area << endl;

}

int main(){
	int arr[] = {4, 2, 1, 5, 6, 3, 2, 4, 2};
	int n = sizeof(arr) / sizeof(int);

	histogram(arr, n);

	return 0;
}