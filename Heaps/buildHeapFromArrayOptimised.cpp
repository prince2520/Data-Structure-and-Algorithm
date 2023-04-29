#include <iostream>
#include <vector>
using namespace std;

bool minHeap = false;

bool compare(int a, int b){
	if(minHeap){
		return a < b;
	}else{
		return a > b;
	}
}

void heapify(vector<int> &v, int idx){
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
		heapify(v,min_index);
	}

}

void buildHeapOptimised(vector <int> &v){

	for(int i = (v.size()-1)/2; i>=1; i--){
		heapify(v, i);
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

	buildHeapOptimised(v);

	print(v);
	

	return 0;
}