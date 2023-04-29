#include <iostream>

using namespace std;

void upper_lower(int ch){
	if( 64<ch && ch<91 ){
		cout << "UPPERCASE";
	}else if( 96<ch && ch<123 ){
		cout << "lowercase";
	}else{
		cout << "Invalid";
	}
} 

int main() {
	char ch;
	cin >> ch;

	upper_lower(int(ch));

	return 0;
}