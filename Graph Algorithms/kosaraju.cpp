#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector<int> *graph, bool *visited, int node, vector<int> &stack){
	visited[node] = true;

	for(auto nbr: graph[node]){
		if(!visited[nbr]){
			dfs(graph, visited, nbr, stack);
		}
	}

	stack.push_back(node);
}

void dfs_rev(vector<int> *revGraph, bool *visited, int node){
	visited[node] = true;

	cout << node << " ";

	for(auto nbr: revGraph[node]){
		if(!visited[nbr]){
			dfs_rev(revGraph, visited, nbr);
		}
	}

}



void solve(vector<int> *graph, vector<int> *revGraph, int n){
	bool visited[n];
	memset(visited, 0, n);

	vector <int> stack;

	// Step 1 - need to store finish time;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			dfs(graph, visited, i, stack);
		}
	}

	// Step 2 -> reverse 

	// Step 3-> reverse Dfs;
	memset(visited, 0, n);

	char comp = 'A';
	for(int i=stack.size()-1; i>=0; i--){
		int node = stack[i];
		if(!visited[i]){
			cout << "Component " << comp << " -> ";
			dfs_rev(revGraph, visited, node);
			comp++;
			cout << endl;
		}
	}

}

int main(){
	int n;
	cin >> n;

	vector<int> graph[n];
	vector<int> revGraph[n];

	int m;
	cin >> m;

	while(m--){
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		revGraph[y].push_back(x);
	}

	solve(graph, revGraph, n);


	return 0;
}