#include <iostream>
#include <queue>
using namespace std;

int join_ropes(int *arr, int n){

	priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);

	int cost = 0;

	while(pq.size() > 1){
		int A = pq.top();
		pq.pop();

		int B = pq.top();
		pq.pop();

		int new_cost = A+B;

		cost += new_cost;

		pq.push(new_cost);
	} 

	return cost;
}

int main(){

	int ropes[] = {4, 3, 2, 6};

	int n = sizeof(ropes) / sizeof(int);

	cout << join_ropes(ropes, n) << endl;
	
	return 0;
}