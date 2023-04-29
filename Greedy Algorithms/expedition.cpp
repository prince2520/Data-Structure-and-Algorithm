#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.first > p2.first;
}

int main(){
	int t;
	cin >> t;

	int d, f;


	while(t--){
		int n;
		cin >> n;

		int flag;
		int ans = 0;

		vector<pair<int,int>> v;

		for(int i=0; i<n; i++){
			cin >> d >> f;

			v.push_back(make_pair(d,f));
		} 

		sort(v.begin(), v.end(), compare);

		int D, F;

		cin >> D >> F;


		for(int j=0; j<n; j++){
			v[j].first = D - v[j].first;

		}

		int x=0;
		int prev = 0;

		priority_queue< int > p;

		while(x<n){
			if(F>=(v[x].first - prev)){
				F = F-(v[x].first -prev);
				p.push(v[x].second);
				prev = v[x].first;
				

			}else{

				if(p.empty()){
					flag = 1;
					break;
				}

				int top = p.top();
				F += top;
				p.pop();

				ans =  ans+1;
				continue;
			}

			x++;
		}

		if(flag == 1){
			cout << -1 << endl;
			continue;
		}

		D = D - v[n-1].first;

		if(F>=D){
			cout << ans << endl;
			continue;
		}

		while(F<D){
			if(p.empty()){
				flag = 1;
				break;
			}

			F+=p.top();
			p.pop();

			ans+=1;
		}

		if(flag == 1){
			cout << -1 << endl;
			continue;
		}





	}



	return 0;
}