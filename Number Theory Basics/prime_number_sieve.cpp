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
	p[1] = 1;
}


int main(){

	int n; 
	cin >> n;

	int p[10005] = {0};

	prime_sieve(p);

	int i=0;

	while(i<=n){
		if(p[i] == 1){
			cout << i << " " ;
		}
		i++;
	}


	return 0;
}