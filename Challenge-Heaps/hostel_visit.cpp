#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
class maxHeap{
	vector<ll> v;

	void heapify(int idx){
		int left = 2 * idx;
		int right = left + 1;

		int max_idx = idx;
		int last = v.size() - 1;

		if(left <= last and v[left] > v[max_idx]){
			max_idx = left;
		}

		if( right <= last and v[right] > v[max_idx]){
			max_idx = right;
		}


		if(max_idx != idx){
			swap(v[max_idx], v[idx]);
			heapify(max_idx);
		}
	}



public:

	maxHeap(){
		v.push_back(-1);
	}

	void push(ll d){

		v.push_back(d);

		int idx = v.size()-1;
		int parent = idx/2;

		while(idx>1 and v[idx] > v[parent]){
			swap(v[idx], v[parent]);

			idx = parent;
			parent = parent/2;
		}
	}

	void pop(){
		swap(v[1], v[v.size()-1]);

		v.pop_back();

		heapify(1);
	}

	ll top(){
		return v[1];
	}

	int size(){
		return v.size() - 1;
	}
};



int main(){
	int query, kth;
	cin >> query >> kth;

	int opt;

	maxHeap m;

	int i=0;

	while(i < query){
		i++;

		cin >> opt;

		if(opt == 2){
			cout << m.top() << endl;
		}else{

			ll x, y;
			cin >> x >> y;

			ll distance = x*x + y*y;

			if(m.size() < kth){
				m.push(distance);	
			}else{
				if(distance < m.top()){
					m.pop();
					m.push(distance);
				}
			}

		}

	}

	return 0;
}