#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector <int> bellman_ford(int v, int src, vector<vector<int>> edges){

	vector <int> dist(v+1, INT_MAX);

	dist[src] = 0;

	for(int i=0; i<(v-1); i++){

		for(auto edge: edges){
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if( dist[u]!=INT_MAX and dist[v] > dist[u] + wt){
				dist[v] = dist[u] + wt;
			}
		}
	}

	for(auto edge: edges){
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if( dist[u]!=INT_MAX and dist[v] > dist[u] + wt){
			cout << "NEGATIVE CYCLE CONTAINS! " << endl;
			exit(0);
		}
	}

	return dist;	
}

int main(){
	int n, m;
	cin >> n >> m;


	vector<vector<int>> edges;

	int u, v, wt;

	for(int i=0; i<m; i++){
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}

	// Bellman ford algorthim

	vector<int> dists = bellman_ford(n, 1, edges);

	for(int i=1; i<=n ; i++){
		cout << "Node " << i << " is at dist " << dists[i] << endl; 
	}


	return 0;
}