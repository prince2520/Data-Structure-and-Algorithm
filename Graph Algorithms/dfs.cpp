#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

template <typename T>

class Graph{
	map<T, list<T>> l;

public:
	void addEdge(T x, T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited){

		cout << src << " ";
		visited[src] = true;

		for(T ngbr : l[src]){
			if(!visited[ngbr]){
				dfs_helper(ngbr, visited);
			}
		}
	}

	void dfs(T src){
		map<T, bool> visited;

		for(auto p : l){
			T node = p.first;
			visited[node] = false;
		}

		dfs_helper(src, visited);


	}
};

int main(){
	Graph <int> g;
	g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);

	//g.bfs(0);
	g.dfs(0);


	return 0;
}