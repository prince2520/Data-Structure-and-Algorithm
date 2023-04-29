#include <iostream>
using namespace std;

void generate_subsequence(char input[], char output[], int i, int j){

	// Base case
	if(input[i]=='\0'){
		output[j] = '\0';
		cout << output << endl;
	
		return;
	}

	// Rec case

	output[j] = input[i];
	// Include
	generate_subsequence(input, output, i+1, j+1);

	// Exclude
	generate_subsequence(input, output, i+1, j);


}

int main(){
	char input[] = "abc";
	char output[10];

	generate_subsequence(input, output, 0, 0);

	return 0;
}