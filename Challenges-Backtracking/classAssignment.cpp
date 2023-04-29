#include <iostream>
using namespace std;

void class_assignment(char out[], int n, int i, int &count){
	// Base case 
	if(i==n){
		out[i] = '\0';
		count++;
		return;
	}

	// Rec case

	out[i] = 'a';
	class_assignment(out, n, i+1, count);

	if(out[i-1] != 'b'){
		out[i] = 'b';
		class_assignment(out, n, i+1, count);
	}
}

int main(){
	int t;
	cin >> t;


	for(int i=0; i<t; i++){
		int n;
		cin >> n;

		int count = 0;

		char out[25];

		class_assignment(out, n, 0, count);

		cout << "#"<< i+1 << " : " << count << endl;

	}
	
	return 0;
}