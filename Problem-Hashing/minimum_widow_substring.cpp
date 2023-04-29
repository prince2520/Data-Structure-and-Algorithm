#include <iostream>
#include <climits>
#include <string>
using namespace std;

string find_window(string s, string p){
	int SL = s.length();
	int PL = p.length();

	int FS[256] = {0};
	int FP[256] = {0};


	// Add freq of pattern in freq pattern arr
	for(int i=0; i<PL; i++){
		char ch = p[i];
		FP[ch]++;
	}

	int cnt = 0;
	int start = 0;
	int min_idex = -1;
	int min_len = INT_MAX;

	for(int j=0; j<SL ;j++){
		char ch = s[j];
		FS[ch]++; 

		if(FP[ch]!=0 and  FS[ch] <= FP[ch]){
			cnt+=1;
		}

		if(cnt == PL){

			char temp = s[start];

			while(FP[temp] == 0 or FS[temp] > FP[temp]){
				FS[temp]--;
				start++;
				temp = s[start];
			}

			int window_len = j-start+1;

			if( window_len < min_len){
				min_idex = start;
				min_len = window_len;
			}
		}
	}

	if(min_idex == -1){
		return "NONE";
	}


	return s.substr(min_idex, min_len);
}

int main(){
	string s = "qwerty asdfgh qazxsw";
	string p = "qas";

	cout << find_window(s, p);

	return 0;
}