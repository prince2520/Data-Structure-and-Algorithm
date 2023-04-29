#include <iostream>
#include <stack>
using namespace std;

void stock_span(int *arr, int n){

	stack<int> stk;
	int *span = new int[n];

	stk.push(0);
	span[0] = 1;

	for(int i=1; i<n; i++){

		while(!stk.empty() and arr[i] > arr[stk.top()]){
			stk.pop();
		}

		if(stk.empty()){
			span[i] = i+1;
		}else{
			span[i] = i - stk.top();
		}

		stk.push(i);
	}


	for(int i=0; i<n; i++){
		cout << span[i] << " "; 
	}
	cout << "END" << endl;

}

int main(){
	int n;
	cin >> n;

	int *arr = new int[1000000];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	stock_span(arr, n);

	delete [] arr;
	
	return 0;
}