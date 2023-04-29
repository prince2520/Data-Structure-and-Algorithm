#include <iostream>
#include <vector> 
using namespace std;

vector <int> prime_sieve(int p[1000], int n){

	// special case 
	p[2] = 1;
	p[1] = p[0] = 1;


	// first mark all odd number's prime
	for(int i = 3; i <= n; i += 2){
		p[i] = 1;
	}

	for(int i = 3; i <= n; i += 2){
		if(p[i] == 1){
			for(int j = i*i; j<=1000; j = j + i){
				p[j] = 0;
			}
		}
	}

	vector<int> primes;
	primes.push_back(2);

	for(int i=3; i<= n; i+=2){
		if(p[i] == 1){
			primes.push_back(i);
		}
	} 

	return primes;
}


vector <int> factorize(int m, vector <int> &primes){

	vector<int> factors;
	factors.clear();

	int i=0;
	int p = primes[0];

	while(p*p <= m){

		if(m%p == 0){
			factors.push_back(p);
			while(m%p == 0){
				m = m/p;
			}
		}

		i++;
		p = primes[i];
	}

	if(m!=1){
		factors.push_back(m);
	}

	return factors;
}

int main(){

	int N = 1000;
	int p[N] = {0};

	vector <int> primes = prime_sieve(p, 100);


	int t;
	cin >> t;

	while(t--){
		int no;
		cin >> no;

		vector <int> factors = factorize(no, primes);

		for(auto f : factors){
			cout << f << " " << endl;
		}
	}


	return 0;
}