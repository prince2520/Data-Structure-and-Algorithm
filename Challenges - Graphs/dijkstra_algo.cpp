#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define ll long long

class Graph{
	vector<pair<int, int>> *l; // Ex :- x->(y, wt)
	int v;
public:
	Graph(int v){
		this->v = v;
		l = new vector<pair<int,int>>[v+1];
	}

	void addEdge(int x, int y, int wt){
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	void dijkstra_algo(int src){
		ll dist[v+1];

		for(int i=0; i<=v; i++){
			dist[i] = INT_MAX;
		}

		dist[src] = 0;

		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

		q.push({0, src});

		while(!q.empty()){
			auto node = q.top();
			q.pop();

			int x = node.second;

			for(auto nbr: l[x]){
				int y = nbr.first;
				int wt = nbr.second;

				if(dist[y] > dist[x] + wt){
					dist[y] = dist[x] + wt;
					q.push({dist[y], y});
				}
			}
		} 

		for(int i=1; i<v; i++){
			if(src == i){
				continue;
			}
			if(dist[i] >= INT_MAX)
				cout << -1 << " ";
			else
				cout << dist[i] << " ";
		}

		cout << endl;

	}
};

int main(){
	int t;
	cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;

		Graph g(n+1);

		for(int i=0; i<m; i++){
			int x, y, wt;
			cin >> x >> y >> wt;

			g.addEdge(x, y, wt);
		} 

		int src; 
		cin >> src;

		g.dijkstra_algo(src);

	}



	return 0;
}