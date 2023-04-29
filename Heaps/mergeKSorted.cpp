#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair <int, pair<int, int>> node;

void  mergeKSortedArray(vector<vector<int>> &arr){

	vector <int> result;

	priority_queue<node, vector<node>, greater<node>> pq;

	for(int i=0; i<arr.size(); i++){
		pq.push(make_pair(arr[i][0], make_pair(i, 0)));
	}

	while(!pq.empty()){
		node top = pq.top();

		int x = top.second.first;
		int y = top.second.second;
		int val = top.first;

		result.push_back(val);

		pq.pop();

		if(y+1 < arr[x].size()){
     		pq.push(make_pair(arr[x][y+1], make_pair(x, y+1)));
		}
	}

	for(auto it: result){
		cout << it << " ";
	}
	cout << endl;

}

int main(){
	vector <vector<int>> arr {{2, 6, 12, 15}, {1, 3, 14, 20}, {3, 5, 8, 10}};

	mergeKSortedArray(arr);

return 0;
}