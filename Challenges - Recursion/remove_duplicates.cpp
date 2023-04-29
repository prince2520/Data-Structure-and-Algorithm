#include <iostream>
using namespace std;

void replaceString(char s[],int i, int j){

	int k = j+1; 

	while(s[k]!='\0'){
		s[i+1] = s[k];
		k++;
		i++;
	}

	s[i+1] = '\0';
}


void removeDuplicates(char s[], int i){
	
	// Base case 
	if(s[i] =='\0'){
		return;
	}

	// Rec case 
	int j = i;

	while( s[j+1] == s[i]){
		j++;
	}

	if(j!=i){
		replaceString(s, i, j);
	}

	removeDuplicates(s, i+1);
}

int main(){
	char s[1000];
	cin >> s;

	removeDuplicates(s, 0);

	cout <<s << endl;

	return 0;
}