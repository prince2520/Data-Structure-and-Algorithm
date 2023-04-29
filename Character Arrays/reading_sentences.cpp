#include <iostream>
using namespace std; 


void readline( char a[], int maxLen, char delim = '$'){
	int i = 0;
	char ch  = cin.get();

	while( ch != delim){
		a[i] = ch;
		
		i++;

		if(i == (maxLen-1)) {
			break;
		} 

		ch = cin.get();
	}

	a[i] = '\0';
}

int main() {
	char a[100];

	/*readline(a, 100, '$');*/
	cin.getline(a, 100 , '$');
	cout << endl;
	cout << a << endl;
	
	return 0;
}