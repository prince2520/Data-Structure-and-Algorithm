#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Graph{
	int v;
	vector <int> *l;

public:

	Graph(int v){
		this->v = v;
		l = new vector<int>[v+1];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs(int node, bool *visited, ll &n){
		visited[node] = true;

		n++;

		for(auto nbr: l[node]){
			if(!visited[nbr]){
				dfs(nbr, visited, n);
			}
		}
	}

	ll pairing(){

		bool visited[v+1];

		for(int i=0; i<v; i++)
			visited[i] = false;

		ll ans = 0;

		for(int i=0; i<v; i++){
			if(!visited[i]){
				ll n = 0;
				dfs(i, visited, n); 
				
				ans += (v-n)*n;
			}
		}

		return ans/2;
	}

};


int main(){

	int n, m;
	cin >> n >> m;

	Graph g(n);

	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;

		g.addEdge(x, y);
	}

	cout << g.pairing() << endl;



	return 0;
}