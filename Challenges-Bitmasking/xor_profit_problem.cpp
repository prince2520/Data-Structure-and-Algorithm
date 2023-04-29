#include <iostream>
using namespace std;

int max_xor(int res){

	int pos = 0;

	while(res>0){
		res = res >> 1;
		pos++;
	}

	return pos ;

}


int main(){
	int a, b;

	cin >> a >> b;

	cout << (1<<max_xor(a^b)) << endl;

	return 0;
}