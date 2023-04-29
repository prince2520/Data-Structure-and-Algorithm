#include <iostream>
#include <string>

using namespace std;

bool is_cb_number(string cbstr){
	long long cb_num = stoll( cbstr, nullptr, 10);

	int cb_valid[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

	if(cb_num == 0 || cb_num == 1){
		return false;
	}

	int size_cb_valid = sizeof(cb_valid)/sizeof(int);

	for(int i=0; i<size_cb_valid; i++){
		if(cb_num == cb_valid[i]){
			return true;
		}
	}

    bool is_valid = true;

	for(int i=0; i<size_cb_valid; i++){
		if(cb_num%cb_valid[i] == 0){
			is_valid = false;
			break;
		}
	}

	return is_valid;

}

int main(){
	int size;
	cin >> size;

	string cb_num;

	cin >> cb_num;

	int cb_count = 0;

	for(int i=0; i<=cb_num.length(); i++){
		for(int j=1; j<=cb_num.length()-i; j++){
			string cbstr =  cb_num.substr(i,j);

			if(is_cb_number(cbstr)){
				cout << cbstr << endl; 
				cb_count += 1;
				i = i + j - 1;
			}
		}
	}

	cout << cb_count ;

	return 0;
}