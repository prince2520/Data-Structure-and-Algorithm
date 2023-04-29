#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void max_frequency(string s){

	int max_char = 0;

	int cum_char = 1;

	char ch = ' ' ;

	for(int i=0; i<s.length(); i++){

		cum_char += 1;
		
		if(s[i] != s[i+1]){
			cum_char = 1;
		}

		if(cum_char >= max_char){
			ch = s[i];
			max_char = cum_char;
		}
	}

	cout << ch;
}

int main(){
	string s;
	getline(cin,s);

	sort(s.begin(), s.end());

	max_frequency(s);


	return 0;
}