#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
	vector <pair <int,int>> *l;
	int v;

public:
	Graph(int n){
		v = n;
		l = new vector<pair<int,int>> [n+1];
	}

	void addEdge(int x, int y, int w){
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst(){
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // pair<weight, edge>
		
		bool visited[v+1]{0};


		q.push({0, 0});

		int ans = 0;

		while(!q.empty()){
			auto node = q.top();
			q.pop();

			int val = node.second;
			int w = node.first;

			if(visited[val]){
				continue;
			}

			ans += w;
			visited[val] = true;

			for(auto nbr: l[val]){
				if(!visited[nbr.first]){
					q.push({nbr.first, nbr.second});
				}
			}
		}
		return ans;
	}
};

int main(){
	Graph g(6);
	// x, y, w;
	g.addEdge(0, 1, 1);
	g.addEdge(0, 3, 2);
	g.addEdge(0, 2, 2);
	g.addEdge(1, 2, 3);
	g.addEdge(2, 3, 3);
	g.addEdge(1, 3, 2);

	cout << g.prim_mst() << endl;


	return 0;
}