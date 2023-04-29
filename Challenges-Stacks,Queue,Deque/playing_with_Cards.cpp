#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void prime_seive(int *prime, vector<int> &v){
	prime[0] = prime[1] = 0;
	prime[2] = 1;

	v.push_back(2);

	for(int i=3; i<1000; i=i+2){
		prime[i] = 1;
	}

	for(int i=3; i<1000; i=i+2){
		if(prime[i]==1){
			v.push_back(i);
			for(int j=i*i; j<1000; j=j+i){
				prime[j] = 0;
			}
		}
	}
}

void playing_with_cards(stack<int> a, int n, int q){
	
	int *prime = new int[100000]{0};
	vector <int> v;
	prime_seive(prime, v);

	int it = 0;

	stack<int> b;
	stack<int> a1;

	while(it<q){
		while(!a.empty()){
			if(a.top()%v.at(it) == 0){
				b.push(a.top());
			}else{
			    a1.push(a.top()); 
			}
			a.pop();
		}
		
	    while(!b.empty()){
			cout << b.top() << endl;
			b.pop();
	    }

 		a = a1;
		while(!a1.empty()){
			a1.pop();
		}
		it++;
	}

	while(!a.empty()){
		cout << a.top() << endl;
		a.pop();
	}

	delete prime;
}

int main(){
	int n, q;
	cin >> n >> q;

	stack<int> a;

	int d;
	for(int i=0; i<n; i++){
		cin >> d;
		a.push(d);
	}

	playing_with_cards(a, n, q);	

	return 0;
}