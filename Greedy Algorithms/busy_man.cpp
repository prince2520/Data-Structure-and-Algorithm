#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	int t;
	cin >> t;

	vector<pair<int,int>> v;

	int n, s, e;

	while(t--){
		
		cin >> n;

		for(int i=0; i<n; i++){

			cin >> s >> e;

			v.push_back(make_pair(s, e));
		}

		sort(v.begin(), v.end(), compare);

		int res = 1;
		int endTime = v[0].second;

		for(int i=1; i<n; i++){

			if(v[i].first >= endTime){
				endTime = v[i].second;
				res += 1;
			}
		}

		cout << res << endl; 

		v.clear();
	}



	return 0;
}