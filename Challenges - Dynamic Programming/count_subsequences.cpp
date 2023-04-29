#include <iostream>
#include <set>
using namespace std;

void count_subsequence(char *s, char* o, int i, int j, set <string> &m){
	// Base case 
	if(s[i]=='\0'){
		o[j] = '\0';
		m.insert(o);
		return;
	}

	// Rec case 
	o[j] = s[i];

	// Include
	count_subsequence(s, o, i+1, j+1, m);

	// Not include  
	count_subsequence(s, o, i+1, j, m);	
}

int main(){
	int t;
	cin >> t;

	while(t--){
		char *s = new char[100000];
		cin >> s;

		char *o = new char[100000];
		set <string>  m;

		count_subsequence(s, o, 0, 0, m);

		cout << m.size() << endl;

		delete [] s;
		delete [] o;

	}


	return 0;
}
