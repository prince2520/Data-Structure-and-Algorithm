#include <iostream>
#include <string>

using namespace std;

void ascii_difference(string str){
	cout << str[0];

	for(int i=1; i<str.length(); i++){
		
		int asci_diff_value = int(str[i])-int(str[i-1]);

		cout << asci_diff_value <<str[i];
	}

}

int main(){
	string str;
	cin >> str;

	ascii_difference(str);

	return 0;
}