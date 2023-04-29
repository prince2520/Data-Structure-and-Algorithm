#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	list <int> *l; 
	int V;

public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
	}

	void topological_sort(){
		// Intialize to 0;
		int indegree[V] = {0};

		for(int i=0; i<V; i++){
			for(auto node: l[i]){
				indegree[node]++;
			}
		}

		queue<int> q;

		for(int i=0; i<V; i++){
			if(indegree[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(int nbr: l[node]){
				indegree[nbr]--;
				if(indegree[nbr]==0){
					q.push(nbr);
				}
			}

			cout << node << " -> ";
		}
		
		cout << endl;



	}


};

int main(){
	Graph g(6);

	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(4, 5);

	g.topological_sort();

	return 0;
}