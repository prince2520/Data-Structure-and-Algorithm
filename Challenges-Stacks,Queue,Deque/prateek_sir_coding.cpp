#include <iostream>
#include <stack>
using namespace std;

void prateek_sir_coding(int q){
	int opt;

	stack <int> stk;

	while(q--){
		cin >> opt;

		if(opt == 2){
			int cost;
			cin >> cost;

			stk.push(cost);
		}else{
			if(stk.empty()){
				cout << "No Code" << endl;
			}

			cout << stk.top() << endl;
			stk.pop();
		}
	}
}	


int main(){
	int q;
	cin >> q;

	prateek_sir_coding(q);

	return 0;
}