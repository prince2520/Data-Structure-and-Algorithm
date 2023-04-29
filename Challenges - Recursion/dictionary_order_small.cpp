#include <iostream>
#include <cstring>
#include <set>
using namespace std;

void dictionary_order_small(char ch[], int i, string comp, set <string> &s){

	// Base case

	if(ch[i] == '\0'){
		
		string str(ch);

		if(str < comp){
			s.insert(ch);
		}

		return;
	}


	// Rec case

	for(int j = i ; ch[j]!='\0'; j++){
		swap(ch[i], ch[j]);
		dictionary_order_small(ch, i+1, comp, s);
		swap(ch[i], ch[j]);
	} 

}

int main(){

	char ch[10];
	cin >> ch;

	string comp(ch);

	set <string> s;

	dictionary_order_small(ch, 0, comp, s);

	for(set<string>::iterator it=s.begin(); it != s.end(); it++){
		cout << *it << endl; 
	}

	return 0;
}