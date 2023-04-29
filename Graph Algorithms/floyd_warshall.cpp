#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX 10000

vector <vector <int>> floyd_warshall(vector<vector<int>> graph){

	vector<vector<int>> dists(graph);

	int n = dists.size();

	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
					if(dists[i][j] > dists[i][k] + dists[k][j]){
					dists[i][j] = dists[i][k] + dists[k][j];
				}

			}
		}
	}

	return dists;
}

int main(){
	vector<vector<int>> graph = {
		{0, INT_MAX, -2, INT_MAX},
		{4, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 2},
		{INT_MAX, -1, INT_MAX, 0}
	};


	vector<vector<int>> dists = floyd_warshall(graph);

	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph.size(); j++){
			cout << dists[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}