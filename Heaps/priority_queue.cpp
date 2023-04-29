#include <iostream>
#include <queue>
using namespace std;

int main(){

	priority_queue<int, vector<int>, greater<int>> q;
	//priority_queue<int> q;

	int n;
	cin >> n;

	int num;
	while(n--){
		cin >> num;
		q.push(num);
	}

	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}

	

	return 0;
}