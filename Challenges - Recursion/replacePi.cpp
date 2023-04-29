#include <iostream>
using namespace std;

void addPiValue(char s[]){

	int j=0;

	while(s[j]!='\0'){
		j++;
	}


	for(int i=j; i!=1; i--){
		s[i+2] = s[i];

	}

	s[0] = '3';
	s[1] = '.';
	s[2] = '1';
	s[3] = '4';

}

void replacePi( char s[] ){

	// Base case 
	if(s[0] =='\0'){
		return;
	}


	// Rec case
	if(s[0]=='p' && s[1]=='i'){
		addPiValue(s);
		replacePi(s+4);
	}else{
		replacePi(s+1);
	}

} 


int main(){
	int n;
	cin >> n;

	while(n--){
		char s[1000];
		cin >> s;

		replacePi(s);


		cout<<s<<endl;

	}
	

	return 0;
}