#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 


void compress_string(string str){

	int cum_char = 0;

	for(int i=0; i<str.length(); i++){
		cum_char += 1;

		if(str[i] != str[i+1]){
			cout << str[i] << cum_char;
			cum_char = 0;
		}
	}

}

int main(){
	string str;
	getline(cin, str);
	
	compress_string(str);


	return 0;
}