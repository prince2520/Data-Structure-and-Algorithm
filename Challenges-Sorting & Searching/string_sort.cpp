#include <iostream>
#include <string>
using namespace std;

void string_sort(string s[1000], int n){
	for(int i=0; i<n; i++){
		int index = i;
		for(int j=i+1; j<n; j++){
			if(s[j]<s[index] || s[j].find(s[index]) == 0){
				index = j;
			}
		}
		swap(s[i],s[index]);
	}
}

int main(){
	int n;
	cin >> n;

	string s[1000];

	cin.get();

	for(int i=0; i<n; i++){
		getline(cin, s[i]);
	}

	string_sort(s, n);

	for(int i=0; i<n; i++){
		cout << s[i] << endl;
	}


	return 0;
}