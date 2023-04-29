#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

template <typename T>

class Graph{
	map<T, list<T>> l;

public:
	void addEdge(T x, T y){
		l[x].push_back(y);
	}


	void bfs(T src){
		map<T, int> dist;
		
		queue <T> q;

		for(auto node_pair : l){
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		q.push(src);

		dist[src] = 0;

		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(int nbr : l[node]){
				if(dist[nbr] == INT_MAX){
					q.push(nbr);

					dist[nbr] = dist[node] + 1;
				}
			}
		}

		for(auto node_pair: l){
			T node = node_pair.first;
			int d = dist[node];
			cout << "Node " << node << " Dist from src " << d << endl;
		}
	}

};

int main(){
	int board[50] = {0};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;


	Graph <int> g;
	
	for(int i=1; i<37; i++){
		for(int dice = 1; dice <= 6; dice++){
			int j = i + dice;

			j+= board[j];

			if(j<=36){
				g.addEdge(i, j);
			}
		}
	}

	g.addEdge(36, 36);

	//g.bfs(0);
	g.bfs(1);


	return 0;
}