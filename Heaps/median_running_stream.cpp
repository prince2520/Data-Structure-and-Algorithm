#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue <int> leftHeap;
	priority_queue <int, vector<int>, greater<int>> rightHeap;

	int d;
	cin >> d;

	leftHeap.push(d);

	cout << "Med: " << d << endl;

	float med = d;

	while(d!=-1){
		cin >> d;

		if(leftHeap.size() > rightHeap.size()){
			if( d < med ){
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}else{
				rightHeap.push(d);
			}

			med = (rightHeap.top() + leftHeap.top())/2.0;

		}else if(rightHeap.size() == leftHeap.size()){

			if(d < med){
				leftHeap.push(d);

				med  = leftHeap.top();
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

     		med = (rightHeap.top() + leftHeap.top())/2.0;

		}

		cout << "Med: " << med << endl;

	}

	

	return 0;
}