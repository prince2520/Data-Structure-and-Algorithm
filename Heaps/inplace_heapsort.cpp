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

void heapify(vector<int> &v, int idx, int n){
	int left = 2 * idx;
	int right = left + 1;

	int last = n - 1;
	int min_index = idx;

	if(left <= last and compare(v[left], v[min_index])){
		min_index = left;
	}

	if(right <= last and compare(v[right], v[min_index])){
		min_index = right;
	}

	if(min_index != idx){
		swap(v[idx], v[min_index]);
		heapify(v,min_index, n);
	}

}


void buildHeapOptimised(vector <int> &v){

	for(int i = (v.size()-1)/2; i>=1; i--){
		heapify(v, i, v.size());
	}

}


void heapsort(vector<int> &v){
	buildHeapOptimised(v);

	int n = v.size(); 

	while(n > 1){
		swap(v[1], v[n-1]);
		n--;
		heapify(v, 1, n);
	}
}

void print(vector <int> &v){
	for(auto it: v){
		cout << it << " ";
	}
}

int main(){
	vector <int> v;
	v.push_back(-1);

	int n;
	cin >> n;

	int temp;
	for(int i=0; i<n; i++){
		cin >> temp;
		v.push_back(temp);
	}

	heapsort(v);

	print(v);
	

	return 0;
}