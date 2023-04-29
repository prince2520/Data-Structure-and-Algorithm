#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}

int main(){
	int t;
	cin >> t;


	int n, start, finish;

	while(t--){
		cin >> n;

		vector <pair<int,int>>v;
		
		for(int i=0; i<n; i++){
			cin >> start >> finish;
			v.push_back(make_pair(start, finish));
		}

		sort(v.begin(), v.end(), compare);

		int ans = 0;

		int finishTime = 0;

		for(int i=0; i<n; i++){
			if(v[i].first>=finishTime){
				ans+=1;

				finishTime = v[i].second;
			}
		}

		cout << ans << endl;


	}



	return 0;
}