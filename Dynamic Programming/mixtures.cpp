#include <iostream>
#include <climits>
  
using namespace std;

int cumSum(int *mix, int s, int e){
	int sum =  0;
	for(int i=s; i<=e; i++){
		sum += mix[i];
		sum %= 100;
	}

	return sum;
}

int mixtures(int *mix, int s, int e){
	// Base case 
	if( s==e){
		return 0;
	}

	// Rec case 
	int min_smoke_amount = INT_MAX;
	
	for(int k=s; k<e; k++){
		int smoke_amount = mixtures(mix, s, k) + mixtures(mix, k+1, e) + cumSum(mix, s, k) * cumSum(mix, k+1, e);

		min_smoke_amount = min(smoke_amount, min_smoke_amount);
	}

	return min_smoke_amount;


}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int mix[1000] = {0};

		for(int i=0; i<n; i++){
			cin >> mix[i]; 
		}

		cout << mixtures(mix, 0, n-1) << endl;

	}
	
	return 0;
}