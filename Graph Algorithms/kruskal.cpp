#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DSU{
	int *parent = NULL;
	int *rank = NULL;

public:
	DSU(int n){
		parent = new int[n+1];
		rank = new int[n+1];

		for(int i=0; i<=n; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i){
		// Base case
		if(parent[i]==-1)
			return i;

		// Recursive case
		return parent[i] = find(parent[i]);
	}

	void union_set(int s1, int s2){
		if(s1!= s2){
			if(rank[s2]<rank[s1]){
				parent[s2] = s1;
				rank[s1]+=rank[s2];
			}else{
				parent[s1] = s2;
				rank[s2]+=rank[s1];
			}
		}
	}


	~DSU(){
		if(parent!=NULL){
			delete [] parent;
		}

		if(rank!=NULL){
			delete [] rank;
		}
	}
};

class Graph{
	int v;
	vector<vector<int>> edgeList;
public:
	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v, int w){
		edgeList.push_back({w, u, v});
	}

	int kruskal_mst(){
		sort(edgeList.begin(), edgeList.end());

		DSU d(v);
		int ans=0;

		for(auto edge: edgeList){
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			int s1 = d.find(x);
			int s2 = d.find(y);

			if(s1!=s2){
				d.union_set(s1, s2);
				ans+=w;
			}
		}

		return ans;
	}

};


int main(){
	Graph g(7);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);

	cout << g.kruskal_mst() << endl;




	return 0;
}