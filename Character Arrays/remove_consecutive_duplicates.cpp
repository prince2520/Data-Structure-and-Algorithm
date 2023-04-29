#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char a[]){
	int i= 0;
	int j= 1;
	
	while(i < strlen(a)){
		if(a[i] == a[j]){
			j++;
		}else{
			a[i+1] = a[j];
			i++;
		}
	}
	a[i] = '\0';
}


int main(){
	char a[100];

	cin.getline(a, 100);

	removeDuplicates(a);

	cout << a << endl;

	return 0;
}