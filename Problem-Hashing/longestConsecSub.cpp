#include <iostream>
#include <unordered_set>
using namespace std;

int longestConSub(int *arr, int n){
	unordered_set <int> m;

	//add array element into hashtable
	for(int i=0; i<n; i++){
		m.insert(arr[i]);
	} 

	int len = 1;

	for(int i=0; i<n; i++){

		if(m.find(arr[i] - 1) == m.end()){

			int next_elem = arr[i] + 1;
			int streak_cnt = 1;

			while(m.find(next_elem)!=m.end()){
				next_elem += 1;
				streak_cnt+= 1;
			}

			len = max(len, streak_cnt);

		}
	}

	return len;
}



int main(){
	int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13,17}; 
	int n = sizeof(arr) / sizeof(int);

	cout << longestConSub(arr, n) << endl;


	return 0;
}