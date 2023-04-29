#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
	int t; 
	cin >> t;

	int n, q, d;

	while(t--){
		cin >> n;

		unordered_map<int, bool> um; 
		for(int i=0; i<n; i++){
			cin >> d;
			um[d] = true;
		}

		cin >> q;

		while(q--){
			cin >> d;

			if(um.count(d)!=0){
				cout << "Yes";
			} else{
				cout << "No";
			}

			cout << endl;
		}
	}

	return 0;
}