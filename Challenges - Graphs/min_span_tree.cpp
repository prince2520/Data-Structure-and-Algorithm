#include <iostream>
#include <map>
#include <list>
using namespace std;

class DSU{
	int *parent = NULL;
	int *rank = NULL;
	int v;
public:
	DSU(int v){
		this->v = v;

		parent = new int[v+1];
		rank = new int[v+1];

		for(int i=0; i<=v; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i){
		// Base case 
		if(parent[i] == -1){
			return i;
		}

		return parent[i] = find(parent[i]);
	}

	void union_set(int s1, int s2){
		if(s1!=s2){
			if(rank[s1]<rank[s2]){
				parent[s1] = s2;
				rank[s2]+=rank[s1];
			}else{
				parent[s2] = s1;
				rank[s1]+=rank[s2];
			}

		}
	}

	void print(){
		for(int i=0; i<=v; i++){
			cout << parent[i] << " ";
		}
		cout << endl;
	}


	~DSU(){
		delete [] parent;
		delete [] rank;
	}
};

class Graph{
	int v; 
	map<int ,list<pair<int, int>>> l;

public:

	Graph(int v){
		this->v = v;
	}

	void addEdge(int x, int y, int wt){
		l[wt].push_back({x, y});
	}

	int kruskal_algo(){

		int ans = 0;

		DSU d(v);

		for(auto edges : l){
			int wt = edges.first;


			for(auto edge: edges.second){
				int x = edge.first;
				int y = edge.second;

				int s1 = d.find(x);
				int s2 = d.find(y);

				if(s1!=s2){
					d.union_set(s1, s2);
					ans += wt;
				}
			}
		}

		return ans;

	}

};

int main(){
	int v, e;
	cin >> v >> e;

	Graph g(v);

	for(int i=0; i<e; i++){
		int x, y, wt;
		cin >> x >> y >> wt;

		g.addEdge(x, y, wt);
	} 

	cout << g.kruskal_algo() << endl;

	return 0;
}