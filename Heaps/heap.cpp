#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int> v;
	bool minHeap;

	bool compare(int a, int b){
		if(minHeap){
			return a < b;
		}else{
			return a > b;
		}
	}

	void heapify(int idx){
		int left = 2 * idx;
		int right = left + 1;

		int last = v.size() - 1;
		int min_index = idx;

		if(left <= last and compare(v[left], v[min_index])){
			min_index = left;
		}

		if(right <= last and compare(v[right], v[min_index])){
			min_index = right;
		}

		if(min_index != idx){
			swap(v[idx], v[min_index]);
			heapify(min_index);
		}

	}

public:
	Heap(int default_size = 10, bool type = true){
		v.reserve(default_size);
		v.push_back(-1);
		minHeap = type;
	}

	// Insertion
	void push(int d){

		v.push_back(d);
		int idx = v.size() - 1;
		int parent = idx / 2;


		while(idx > 1 and compare(v[idx], v[parent])){
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent/2;
		}

	}

	int top(){
		return v[1];
	}

	void pop(){
		// Swap 1st element with last element
		swap(v[1], v[v.size()-1]);

		//Remove the last element 
		v.pop_back();

		// Heapify
		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}


};

int main(){
	Heap h;
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int d;
		cin >> d;

		h.push(d);
	}

	cout << endl;

	while(!h.empty()){
		cout << h.top() << " ";
		h.pop();
	}
	

	return 0;
}