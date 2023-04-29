#include <iostream>
#include <list>
using namespace std;

class Graph{
	list <int> *l;
	int v;

public:

	Graph(int v){
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
	}

	bool cycle_helper(int node, bool *visited, bool *stack){

		visited[node] = true;
		stack[node] = true;

		for(auto nbr : l[node]){
			if(visited[nbr] and stack[nbr]){
				return true;
			}else if(!visited[nbr]){
				bool cycle_mil_gya = cycle_helper(nbr, visited, stack);
				if(cycle_mil_gya){
					return true;
				}
			}
		}

		stack[node] = false;

		return false;
	}

	bool contains_cycle(){
		bool visited[v] = {false};
		bool stack[v] = {false};

		return cycle_helper(0, visited, stack);
	}

};

int main(){
	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	//g.addEdge(4, 2); //Back Edge

	if(g.contains_cycle()){
		cout << "Cycle found! " << endl;
	}else{
		cout << "Cycle not found! " << endl;
	}



	return 0;
}