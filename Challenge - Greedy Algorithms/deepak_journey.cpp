#include <iostream>
#include <climits>

using namespace std;

#define ll long long

void minimum_cost(int *cost, int *liter, int n){

	int min_cost_per_liter = INT_MAX;

	ll total_cost = 0;

	for(int i=0; i<n; i++){
		
		min_cost_per_liter = min(cost[i], min_cost_per_liter);

		total_cost += min_cost_per_liter*liter[i];

	}

	cout << total_cost << endl;

}


int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int *cost = new int[100000];
		int *liter = new int[100000];

		for(int i=0; i<n; i++){
			cin >> cost[i];
		}

		for(int i=0; i<n; i++){
			cin >> liter[i];
		}

		minimum_cost(cost, liter, n);


		delete [] cost;
		delete [] liter;
	}


	return 0;
}