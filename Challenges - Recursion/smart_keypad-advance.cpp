#include <iostream>
#include <vector>
#include <string>
using namespace std;

void smart_keypad_advance(vector <string> keypad, string searchIn[], char out[], char num[], int i, int j){
	// Base case
	if(num[i] == '\0'){
		out[j] = '\0';


		for(int k=0; k<=10; k++){
			size_t found = searchIn[k].find(out);
			if( found != string::npos){
				cout << searchIn[k] << endl;
			}
		}

		return;
	}

	// Rec case 

	int digit = num[i] - '0';

	for(int k=0; keypad[digit][k]!='\0'; k++){
		out[j] = keypad[digit][k];

		smart_keypad_advance(keypad, searchIn, out, num, i+1, j+1);
	}

}

int main(){
	vector<string> keypad = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	string searchIn[] = {
            "kartik", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

    char num[10];
    cin >> num;

    char out[20];

    smart_keypad_advance(keypad, searchIn, out,  num, 0, 0);

	return 0;
}