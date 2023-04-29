#include <iostream>
#include <vector>
using namespace std;

void heapify(vector <int> &v,int idx){
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

void buildHeap(vector <int> &v){

	for(int i=2; i<v.size(); i++){

		int idx = i;
		int parent = i/2;

		while(idx>1 and v[idx] > v[parent]){
			swap(v[idx], v[parent]);
			idx = parent;
			parent = idx / 2;
		}
	}
}

void print(vector <int> v){
	for(auto it : v){
		cout << it << " ";
	}
	cout << endl;
}

int main(){
	vector <int> v {-1, 10, 20, 5, 6, 1, 8, 9, 4};

	print(v);

	buildHeap(v);

	print(v);


	return 0;
}