#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<pair<int,int>> l;

public:
	Graph(int V){
		this->V = V;
	}

	void addEdge(int u, int v){
		l.push_back(make_pair(u,v));
	}

	int findSet(int i, int *parent){
		//Base case 
		if(parent[i]==-1)
			return i;

		// Rec case 
		return parent[i] = findSet(parent[i], parent);
	}

	void union_set(int s1, int s2, int *parent, int *rank){
		if(s1 != s2){
			if(rank[s2]<rank[s1]){
				parent[s2] = s1;
				rank[s2]+=rank[s1];
			}else{
				parent[s1] = s2;
				rank[s1]+=rank[s2];
			}
		}
	}

	bool contains_cycle(){
		int parent[V+1];
		int rank[V+1];

		for(int i=0; i<=V; i++){
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto edge: l){
			int s1 = findSet(edge.first, parent);
			int s2 = findSet(edge.second, parent);

			if(s1 != s2){
				union_set(s1, s2, parent, rank);
			}else{
				return true;
			}
		}
		return false;
	}

};

int main(){

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	//g.addEdge(3, 0);

	if(g.contains_cycle()){
		cout << "It is cyclic!" << endl;
	}else{
		cout << "It is not cyclic!" << endl;
	}


	return 0;
}