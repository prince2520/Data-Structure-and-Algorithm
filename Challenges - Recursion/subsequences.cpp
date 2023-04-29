#include <iostream>
using namespace std;

void subsequence(char s[], char out[], int i, int j, int &count){
	
	// Base case
	if(s[i] == '\0'){
		out[j] = '\0';
		cout << out << " ";

		count++;
		return;
	} 

	// Rec case 

	//Exclude
	subsequence(s, out, i+1, j, count);

	//Include
	out[j] = s[i];
	subsequence(s, out, i+1, j+1, count);

}

int main(){
	
	char s[10];
	cin >> s;

	char out[10];

	int count = 0;

	subsequence(s, out, 0, 0, count);
	cout << endl;

	cout << count;

	return 0;
}