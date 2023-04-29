#include <iostream>
#include <set>
using namespace std;

void tricky_permutation(char ch[], int i, set<string> &str){
	
	// Base case
	if(ch[i]=='\0'){
		string s(ch);
		str.insert(s);
		return;
	}

	// Rec case 

	for(int j=i; ch[j]!='\0'; j++){
		swap(ch[i], ch[j]);
		tricky_permutation(ch, i+1, str);
		swap(ch[i], ch[j]);
	}
}

int main(){
	char ch[9];
	cin >> ch;

	set <string> str;

	tricky_permutation(ch, 0, str);

	for(set<string>::iterator it= str.begin(); it!= str.end(); it++){
		cout << *it << endl;
	}

	return 0;
}