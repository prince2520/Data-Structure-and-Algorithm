#include <iostream>
using namespace std;

void moveX(char ch[], int i){
	// Base case
	if(ch[i] == '\0'){
		return;
	}
	// Rec case


	if(ch[i] == 'x'){
		int j = i;
		while(ch[j] == 'x' and ch[j] != '\0'){
			j++;
		}
		if( ch[j] != '\0'){
			swap(ch[i], ch[j]);
		}
	}

	moveX(ch, i+1);
}

int main(){
	char ch[1000];
	cin >> ch;

	moveX(ch, 0);

	cout << ch << endl;

	return 0;
}