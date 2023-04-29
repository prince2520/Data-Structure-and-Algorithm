#include <iostream>
#include <string>
using namespace std;


void binary_sum(string str1, string str2){
	
	for(int i=0; i<str1.length(); i++){
		if(str1[i] != str2[i]){
			cout << '1';
		}else{
			cout << '0';
		}
	}

	cout << endl;
}


int main() {
	int test_case;

	cin >> test_case;

	int i=0;

	while(i<test_case){
		string  str1; 
		string  str2;

		cin >> str1 >> str2;

		binary_sum(str1, str2);


     	i++;
	}

	return 0;
}