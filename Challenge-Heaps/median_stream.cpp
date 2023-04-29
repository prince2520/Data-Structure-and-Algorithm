#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void median_stream(int n){
	priority_queue <int> leftHeap;
	priority_queue <int, vector<int>, greater<int> > rightHeap;

	vector <int> result;

	int d;
	cin >> d;

	leftHeap.push(d);

	result.push_back(d);

	float med = d;

	for(int i=1; i<n; i++){
		cin >> d;

		if(leftHeap.size() > rightHeap.size()){

			if(  d < med){
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}else{
				rightHeap.push(d);
			}

			med = (leftHeap.top() + rightHeap.top()) / 2.0; 


		}else if(leftHeap.size() == rightHeap.size()){
			if(d < med){
				leftHeap.push(d);
				med = leftHeap.top();

			}else{
				rightHeap.push(d);
				med = rightHeap.top();
			}

		}else{

			if(med < d){
				leftHeap.push(rightHeap.top());
				rightHeap.pop();

				rightHeap.push(d);

			}else{
				leftHeap.push(d);
			}

			med = (leftHeap.top() + rightHeap.top()) / 2.0; 
		}

		result.push_back(med);
	}


	for(auto it: result){
		cout << it << " ";
	}

}

int main(){
	

	int t;
	cin >> t;

	for(int i=0; i<t; i++){
		int n;
		cin >> n;

		median_stream(n);

		cout << endl;
	} 

	return 0;
}