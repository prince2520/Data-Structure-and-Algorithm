#include <iostream>
using namespace std;

int findGCD(int num1, int num2){

	return num1 == 0 ? num2 : findGCD(num2, num2%num1);

}

int main(){
	long long num1;
	long long num2;

	cout << findGCD(num1, num2) << endl;

	return 0;
}