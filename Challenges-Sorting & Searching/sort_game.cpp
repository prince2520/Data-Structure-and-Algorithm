#include <iostream>

#include <string>
using namespace std;

void sort_game(pair <string, int> emp[], int n){

	for(int i=0; i<n; i++){
		int lar_sal = i;
		for(int j=i+1; j<n; j++){
			if(emp[j].second > emp[lar_sal].second){
				lar_sal = j;
			}

			if(emp[j].second == emp[lar_sal].second){
				if(emp[j].first < emp[i].first){
					lar_sal = j;
				}
			}
		}
		swap(emp[i], emp[lar_sal]);
	}
}

int main(){
	int sort_num;
	cin >> sort_num;

	int n;
	cin >> n;

	pair <string, int> emp[1000];


	for(int i=0; i<n; i++){
		string name;
		int sal;
		cin >> name >> sal;

		emp[i].first = name;
		emp[i].second = sal;
	}

	sort_game(emp, n);

	for(int i=0; i<n; i++){
		if(emp[i].second >= sort_num){
			cout << emp[i].first << " ";
	     	cout << emp[i].second << endl; 
		}else{
			break;
		}
	}

	return 0;
}