#include <iostream>
using namespace std;

void modular_exponentation(int  a, int  b, int c){
	long ans = 1;

	while(b){

		if(b&1){
			ans = ((ans % c) * (a % c)) % c ;  
		}

		a = ((a % c) * (a % c)) % c;

		b = b >> 1; 
	}

	cout << (ans % c) << endl;
}

int main(){

	int a, b, c;
	cin >> a >> b >> c;

	modular_exponentation(a, b, c);

	return 0;
}