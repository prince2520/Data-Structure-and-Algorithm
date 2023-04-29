#include <iostream>
#include <climits>
using namespace std;

string smallest_str(string str, string pStr){

	int FS[256] = {0};
	int FP[256] = {0}; 

	int PL = pStr.length();
	int SL = str.length();

	for(int j=0; j<PL; j++){
	    char ch = pStr[j];
		FP[ch]++;
	}

	int count = 0;
	int start = 0;
	int min_len  = INT_MAX;
	int min_index = -1;

	for(int i=0; i<SL; i++){
		char ch = str[i];
		FS[ch]++;

		if(FP[ch] !=0 and FS[ch] <= FP[ch]){
			count++;
		}

		if(count == PL){
			char temp = str[start];

			while(FP[temp] == 0 or FS[temp] > FP[temp]){
				FS[temp]--;
				start++;
				temp = str[start];
			}

			int window_len = (i-start+1);

			if(min_len > window_len){
				min_index = start;
				min_len = window_len;
			}
		}
	}

	if(min_index == -1){
		return "No String";
	}

	return str.substr(min_index, min_len);
}

int main(){
	string str;
	getline(cin, str);

	string pStr;
	getline(cin, pStr);

	cout << smallest_str(str, pStr) << endl;

	return 0;
}