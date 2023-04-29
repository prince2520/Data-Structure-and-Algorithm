#include<iostream>
#include<string>
using namespace std;

int chewbacca_number(string num){
	int i=0;
	if(num[0] == '9'){
		i = 1;
		cout << 9;
	}
	for(; i<num.length();i++){
		int numeric = num[i] - '0';
	
		if(9-numeric < numeric){
			cout << 9-numeric;
		}else{
			cout << numeric;
		}
	}
	return 0;
}

int main(){
	string num;
	getline(cin,num);

    chewbacca_number(num); 

}