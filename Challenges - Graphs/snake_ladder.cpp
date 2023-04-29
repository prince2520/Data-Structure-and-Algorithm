#include <iostream>
#include <map>
#include <climits>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int v;
	map<int, list<int>> l;
public:

	Graph(int n){
		v = n;
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
	}

	void print(){
		for(auto edgeList: l){
			cout << edgeList.first << " -> "; 
			for(auto edge: l[edgeList.first])
				cout << edge << " ";

			cout << endl;
		}
	}

	int min_dice_throw(int no_of_board){
		int dist[no_of_board];

		for(int i=0; i<=no_of_board; i++)
			dist[i] = INT_MAX;


		dist[1] = 0;

		queue<int> q;

		q.push(1);

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto nbr: l[node]){
				if(dist[nbr]==INT_MAX){
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
				}

			}

		}
	

		return dist[no_of_board];

	}
};

int main(){
	int t;
	cin >> t;

	for(int j=0; j<t; j++){
		int board[50] = {0};

		int no_of_board, ladder, snake;

		cin >> no_of_board >> ladder >> snake;

		for(int i=0; i<ladder+snake; i++){
			int x, y;
			cin >> x >> y;

			board[x] = y;
		}

		// Make Graph

		Graph g(no_of_board);

		for(int i=1; i<=no_of_board; i++){
			for(int dice=1; dice<=6; dice++){
				if(board[i+dice]!=0){
					g.addEdge(i, board[i+dice]);
				}else{
					g.addEdge(i, i+dice);
				}
			}
		}


		cout << g.min_dice_throw(no_of_board) << endl;


	}



	return 0;
}