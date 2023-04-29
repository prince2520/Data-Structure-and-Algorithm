#include <iostream>
using namespace std;

void addStarString(char s[],int i){
	int j = i;

	for(; s[j] != '\0';){
		j = j+1;
	}

	for(int k=j ;k!=i-1 ;k--){
		s[k+1] = s[k];
	}

	s[i] = '*';
}

void duplicatCharFormat(char s[], int i){
	// Base case
	if(s[i] == '\0'){
		return;
	}

	// Rec case 

	if(s[i-1] == s[i]){
		addStarString(s, i);
	}

	duplicatCharFormat(s, i+1);
}

int main(){
	char s[1000];

	cin >> s;
	
	duplicatCharFormat(s, 1);
	
	cout << s << endl;

	return 0;
}