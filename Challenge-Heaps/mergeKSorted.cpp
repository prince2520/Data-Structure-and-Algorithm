#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, pair<int, int>> node;


void mergeKSortedArray(int *arr, int k, int n){
	priority_queue <node, vector<node>, greater<node>> pq;


	int i = 0;
	int start = 0;

	while(i < k){
		pq.push(make_pair(arr[start], make_pair(start, start + n)));

		start = start + n;

		i++;
	}

	int s, e;

	while(!pq.empty()){
		node p = pq.top();

		cout << p.first << " ";

		s = p.second.first;
		e = p.second.second;

    	pq.pop();


		if(s+1 < e){
			pq.push(make_pair(arr[s+1], make_pair(s+1, e)));
		}
	}

}

int main(){
	int k, n;
	cin >> k >> n;

	int *arr = new int[ n*k + 1];

	for(int i=0; i<n*k; i++){
		cin >> arr[i];
	}

	mergeKSortedArray(arr, k, n);

	delete [] arr;	

	return 0;
}