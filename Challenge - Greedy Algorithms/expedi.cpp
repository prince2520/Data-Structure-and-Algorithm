#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.first > p2.first;
}

void expedi(int D, int F, int n, vector<pair<int,int>> &v){

	bool flag = false;

	sort(v.begin(), v.end(), compare);

	for(int i=0; i<n; i++){
		v[i].first = D - v[i].first;
	}

	priority_queue<int> q;

	int x = 0;
	int prev = 0;
	int ans = 0;

	while(x<n){

		if(F>=(v[x].first - prev)){

			F = F - (v[x].first - prev);
			q.push(v[x].second);
			prev = v[x].first;

		}else{

			if(q.empty()){
				cout << -1 << endl;
				return;
			}

			F+= q.top();
			q.pop();
			ans += 1;
			continue;
		}

		x++;
	}


	if(flag){
		cout << -1 << endl;
		return;
	}

	D = D - v[n-1].first;

	if(F>=D){
		cout << ans << endl;
		return;  
	}


	while(F<D){
		if(q.empty()){
			cout << -1 << endl;
			return;
		}

		F+=q.top();
		q.pop();
		ans+=1;
	}

	cout << ans << endl;

}

int main(){
	int n;
	cin >> n;

	int d, f, D, F;

	vector<pair<int,int>> v;

	for(int i=0; i<n; i++){
		cin >> d >> f;

		v.push_back(make_pair(d, f));
	}

	cin >> D >> F;

	expedi(D, F, n, v);

	return 0;
}