#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
#include <string>
using namespace std;

template <typename T>

class Graph{
	map<T, list<T>> l;

public:
	void addEdge(T x, T y){
		l[x].push_back(y);
	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){

		visited[src] = true;

		for(T ngbr : l[src]){
			if(!visited[ngbr]){
				dfs_helper(ngbr, visited, ordering);
			}
		}

		ordering.push_front(src);
	}

	void dfs(){
		map<T, bool> visited;
		list<T> ordering;

		for(auto p : l){
			T node = p.first;
			visited[node] = false;
		}

		for(auto p: l){
			T node = p.first;

			if(!visited[node]){
				dfs_helper(node, visited, ordering);
			}
		}

		for(auto o:ordering){
			cout << o << " -> " ;
		}

	}
};

int main(){
	Graph <string> g;
	g.addEdge("Python", "Data Reprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Data Reprocessing", "ML Basics"); 
    g.addEdge("PyTorch", "Deep Leaning");
    g.addEdge("ML Basics", "Deep Leaning");
 
    g.addEdge("Data Set", "Face Recognition");
    g.addEdge("Deep Leaning", "Face Recognition");


	g.dfs();


	return 0;
}