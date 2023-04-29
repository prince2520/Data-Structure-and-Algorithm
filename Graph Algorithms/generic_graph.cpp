#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>
using namespace std;

class Graph{
	unordered_map<string, list<pair<string, int>>> l;
public:
	void addEdge(string x, string y, bool biDir, int wt){
		l[x].push_back(make_pair(y, wt));

		if(biDir){
			l[y].push_back(make_pair(x, wt));
		}
	}

	void printAdjList(){
		for(auto p: l){
			string city = p.first; 
			cout << city << " -> ";

			list<pair<string, int>>  ngbrs = p.second;

			for(auto ngbr : ngbrs){
				cout << "(" << ngbr.first << ", " << ngbr.second << ") ";
			}
			cout << endl;

		}
	}

};

int main(){
	Graph g;

	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);

	g.printAdjList();



	return 0;
}