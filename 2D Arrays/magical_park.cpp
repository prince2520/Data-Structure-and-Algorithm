#include <iostream>
using namespace std;
 
void magical_park(char a[][100], int m, int n, int k, int s){
	bool success = true;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			char c = a[i][j];

			if(s<k){
				success = false;
				break;
			}

			if(c == '.'){
				s -= 2;
			}else if(c == '*'){
				s += 5;
			}else{
				break;
			}

			if(j != n-1){
				s -= 1;
			}
		}
	}

	if(success){
		cout << "YES" << endl;
		cout << s <<endl;
	}else{
		cout << "NO" << endl;
		cout << s << endl;
	}

}

int main() {
	char a[100][100] = {0};
	int m, n, k, s;
	cin >> m >> n >> k >> s;

	for (int i = 0; i < m; i++){
		for (int j =0; j < n; j++){
			cin>> a[i][j];
		}
	}

	magical_park(a, m, n, k, s);

	return 0; 
}