#include <iostream>
#include <cstring>
using namespace std;

class fun{
public:
	void operator()(string s){
		cout << "fun with "<< s; 
	}

};

int main(){
	fun f;

	f("C++");
	

	return 0;
}