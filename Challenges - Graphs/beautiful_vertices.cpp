#include <iostream>
#include <map>
#include <list>

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

	void dfs_helper(int node, bool *visited, int *parent, int *no_of_child ){

		visited[node] = true;

		int child = 0;

		for(auto nbr: l[node]){
			if(!visited[nbr]){
				parent[nbr] = node;
				child+=1;
				dfs_helper(nbr, visited, parent, no_of_child);
			}
		}

		no_of_child[node] = child;
	}

	void dfs(){
		bool visited[v+1];
		int no_of_child[v+1];
		int parent[v+1];

		for(int i=0; i<=v; i++){
			visited[i] = false;
			no_of_child[i] = 0;
			parent[i] = -1;
		}

		for(int i=1; i<=v; i++){			
			if(!visited[i]){
				dfs_helper(i, visited, parent, no_of_child); 
			}
		}

		int ans = 0;

		for(int i=1; i<=v; i++){
			if(parent[i]>-1 and no_of_child[i] > no_of_child[parent[i]]){
				ans+=1;
			}
		}

		cout << ans << endl;

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

	g.dfs();

	return 0;
}