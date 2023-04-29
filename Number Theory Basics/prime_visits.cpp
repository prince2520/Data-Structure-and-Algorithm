#include <iostream>
using namespace std;

void prime_sieve(int p[1000]){

	// first mark all odd number's prime
	for(int i = 3; i <= 1000; i += 2){
		p[i] = 1;
	}

	for(int i = 3; i <= 1000; i += 2){
		if(p[i] == 1){
			for(int j = i*i; j<=1000; j = j + i){
				p[j] = 0;
			}
		}
	}

	// special case 
	p[2] = 1;
	p[1] = p[0] = 0;
}


int main(){
	int p[1005] = {0};

	prime_sieve(p);

	int csum[1005] = {0};

	for(int i=1; i<=1000; i++){
		csum[i] = csum[i-1] + p[i]; 
	}

	int q;
	cin >> q;


	while(q--){
		int a, b;
		cin >> a >> b;

		cout << csum[b] - csum[a-1] << endl;

	}


	return 0;
}