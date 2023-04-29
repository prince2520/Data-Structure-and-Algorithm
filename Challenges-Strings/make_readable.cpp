#include <iostream>
#include <string>
using namespace std;

void make_readable(string str){
	cout << str[0];
	for(int i=1; i<str.length(); i++){

		if('A'<=str[i] && str[i]<='Z'){
			cout << endl;
			cout << str[i];
		}else{
			cout << str[i];
		}
	}
}

int main(){

	string str;
	getline(cin,str);

	make_readable(str);

	return 0;
}
