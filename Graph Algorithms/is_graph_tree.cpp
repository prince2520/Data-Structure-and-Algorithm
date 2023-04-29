#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list <int> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool is_tree(){

		bool visited[V];
		int parent[V];

		queue<int> q;

		for(int i=0; i<V; i++){
			visited[i] = false;
			parent[i] = i;
		}

		int src = 0;

		q.push(src);

		visited[src] = true;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto nbr: l[node]){
				if(visited[nbr] == true and parent[node]!=nbr){
					return false;
				}
				else if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;
				}
			}
		} 


		return true;

	}
};

int main(){
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(1, 2);
	g.addEdge(0, 3);


	if(g.is_tree()){
		cout << "It is a tree! " << endl;
	}else{
		cout << "It is not a tree! " << endl; 
	}


	return 0;
}