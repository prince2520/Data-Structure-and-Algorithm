#include <iostream>
#include <vector> 
using namespace std;

vector <int> prime_sieve(int p[1000], int n){

	p[2] = 1;
	p[1] = p[0] = 1;


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


int no_of_divsors(int m, vector <int> &primes){

	int i=0;
	int p = primes[0];

	int ans = 1;

	while(p*p <= m){

		if(m%p == 0){
			int cnt = 0;
			
			while(m%p == 0){
				cnt++;
				m = m/p;
			}

			ans = ans * (cnt + 1);
		}

		i++;
		p = primes[i];
	}

	if(m!=1){
		ans = ans * 2;
	}

	return ans;
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

		int divs = no_of_divsors(no, primes);

		cout << divs;
	}

	return 0;
}