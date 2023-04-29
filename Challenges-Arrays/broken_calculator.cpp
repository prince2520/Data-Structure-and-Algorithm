#include <iostream>

using namespace std;

int multiply(int fact[100], int multi_value, int fact_size){

	int carry = 0;

	int size = fact_size; 

	for(int i=0; i < fact_size; i++){
		
		int prod = fact[i] * multi_value + carry;

		fact[i] = prod%10;

      	carry = prod/10;
	} 


	int j = fact_size;

	while(carry!=0){

		fact[j] = carry % 10;
		
		carry = carry / 10;

		size += 1;
		
		j++;
	}

	return size;

}

void factorial(int n){
	int fact[1000] = {1};

	int fact_size = 1;

	for(int i=2; i<=n; i++){
		fact_size = multiply(fact, i, fact_size);
	}

	for(int i=fact_size-1; i>=0; i--){
		cout << fact[i];
	}
}

int main(){
    int n;
    cin >> n;

	factorial(n);

	return 0;
} 