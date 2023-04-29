#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int res = 0, arr[100000]={0};

	for(int i=0; i<n; i++){
		cin >> arr[i];
		res = res ^ arr[i]; 
	}


	int pos = 0;
	int temp = res;

	while((temp&1)!=1){
		temp = temp >> 1;
		
		pos++;
	}


	int a = 0;
	int b = 0;
	int mask= 1>>pos;

	for(int i=0; i<n; i++){
		if((mask & arr[i]) >0){
			a = a^arr[i];
		}
	}

	b = a^res;

	cout << min(a,b) << " " << max(a, b) << endl;


	return 0;
}