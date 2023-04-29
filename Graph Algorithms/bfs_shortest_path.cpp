#include <iostream>
#include <map>
#include <list>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Graph{
	int v;
	map<int, list<int>> l;

public:

	Graph(int v){
		this->v = v;
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void print(){
		for(auto edges: l){
			cout << edges.first << " -> ";

			for(auto edge: edges.second){
				cout << edge << " ";
			}
		}
	}

	void bfs_shortPath(int src){
		int dist[v+1];
		
		for( int i=0; i<=v; i++)
			dist[i] = INT_MAX;

		dist[src] = 0;

		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

		q.push({0, src});

		while(!q.empty()){
			auto node = q.top();
			q.pop();

			for(auto nbr: l[node.second]){
				if(dist[node.second]!= INT_MAX and dist[nbr] > (dist[node.second] + 6)){
					dist[nbr] = dist[node.second] + 6;
					q.push({dist[nbr], nbr});
				}
			}
		} 

		for(int i=1; i<=v; i++){
			if(src==i){
				continue;
			}

			if(dist[i]!=INT_MAX)
				cout << dist[i] << " " ;
			else
				cout << -1 << " ";
		}

		cout << endl;
		
	}
};

int main(){
	int t;
	cin >> t;

	while(t--){
		int m, n;
		cin >> m >> n;

		Graph g(m);

		for(int i=0; i<n; i++){
			int x, y;
			cin >> x >> y;

			g.addEdge(x, y);
		}

		int src;
		cin >> src;

		g.bfs_shortPath(src);
	}



	return 0;
}