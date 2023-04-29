#include <iostream>
#include <map> 
#include <vector>
using namespace std;


int main(){
	int n;
	cin >> n;

	map<int, int> m;

	int d;
	m.insert(make_pair(-1,0));

	for(int i=0; i<n; i++){
		cin >> d;

		if(m.count(d)==0)
			m.insert(make_pair(d, 1)); 
		else
			m[d]+=1;
	}

	int max_val = -1;

	for(auto it: m){
		if(m[max_val] < it.second){
			max_val = it.first;
		}
	}

	cout << max_val << endl;

	return 0;
}