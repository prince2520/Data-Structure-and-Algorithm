#include <iostream>
using namespace std;

int piyush_magic_park(char park[100][100],int m, int n, int k, int s){

	int strength = s;

	int i = 0;


	while(i<m){
		int j = 0;

		while(j<n){			
			
			if(strength < k){
				cout << "NO";
				return 0;
			}

			if(park[i][j] == '.'){
				strength -= 2;
			}else if(park[i][j] == '*'){
				strength += 5; 
			}else{
				break;
			}
			
			if(j!=m-1){
				strength-=1;
			}

			j++;
		}

		i++;
	}


	cout << "YES" << endl;
	cout << strength << endl;

	return 0;
}

int main(){
	int m, n, k, s;

	cin >> m >> n >> k >> s;

	char park[100][100];

	for(int i=0; i<m ; i++){
		for (int j=0; j<n; j++){
			cin >> park[i][j];
		}
	}


	piyush_magic_park(park, m, n, k, s);


	return 0;
}