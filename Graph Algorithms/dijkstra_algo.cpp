#include <iostream>
#include <unordered_map>
#include <climits>
#include <set>
#include <list>

using namespace std;

template <typename T>
class Graph{
	unordered_map<T, list<pair<T,int>>> m;

public:
	void addEdge(T u, T v, int dist, bool biDir=true){
		m[u].push_back(make_pair(v, dist));

		if(biDir){
			m[v].push_back(make_pair(u, dist));
		}
	}

	void printAdj(){

		for(auto p: m){
			cout << p.first << " -> ";

			for(auto child: p.second){
				cout << "(" << child.first << ", " << child.second << ") "; 
			}

			cout << endl;
		}

	}
	

	void dijsktraSSSP(T src){
		unordered_map<T, int> dist;

		for(auto j:m){
			dist[j.first] = INT_MAX;
		}

		set<pair<int, T>> s;

		dist[src] = 0;
		
		s.insert(make_pair(0, src));

		while(!s.empty()){
			auto p = *(s.begin());

			T node = p.second;  // city
			int nodeDist = p.first; // distance 

			s.erase(s.begin());

			for(auto child: m[node]){
				
				if((nodeDist + child.second) < dist[child.first]){

					pair<int, T> pr = make_pair(nodeDist+child.second, child.first);

					auto f = s.find(make_pair(dist[child.first], child.first));

					if(f!=s.end())
						s.erase(f);

					s.insert(pr);

					dist[child.first] = nodeDist + child.second;

				}
			}
		}

		for(auto child : dist){
			cout << child.first << " to the distance " << src << " is " << child.second << endl;
		}

	}

};

int main(){

	/*Graph <int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.printAdj();*/

	Graph <string> india;
	india.addEdge("Amritsar", "Delhi", 1);
	india.addEdge("Amritsar", "Jaipur", 4);
	india.addEdge("Jaipur", "Delhi", 2);
	india.addEdge("Jaipur", "Mumbai", 8);
	india.addEdge("Bhopal", "Agra", 2);
	india.addEdge("Mumbai", "Bhopal", 3);
	india.addEdge("Agra", "Delhi", 1);
	// india.printAdj();
	india.dijsktraSSSP("Amritsar");




	return 0;
}