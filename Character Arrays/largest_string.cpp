#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;
	cin >> n;

	cin.get();

	char a[100];
	char largest_string[100];
	int largest = 0;
	
	for(int i=0; i < n; i++){
		cin.getline(a,100);

		int len = 0;
		len = strlen(a);

		if(largest < len){
			largest = len;
			strcpy(largest_string, a);
		}
	}

	cout << largest_string << " and " << largest << endl; 

	return 0;
}