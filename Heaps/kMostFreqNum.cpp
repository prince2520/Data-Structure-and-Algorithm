#include <iostream>
#include <queue>
using namespace std;

class compare{
public:
	bool operator()(pair<int,int> A, pair <int, int> B){

	}
};

void kMostFreqNumStream(int n, int k){

	int freq[1000] = {0};

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;   

	int d;

	for(int i=0; i<n; i++){
		cin >> d;

		freq[d]++;

		pq.push(make_pair())

	}



}

int main(){
	int t;
	cin >> t;

	int n, k;

	for(int i=0; i<t; i++){
		cin >> n >> k;


	}


	return 0;
}