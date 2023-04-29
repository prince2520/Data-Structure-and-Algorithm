#include <iostream>
using namespace std;

void search_element_2d_array_sort(int arr[100][100], int m, int n, int key){
	int i = 0;
	int j = n-1;

	while(i < m && j >=0){
		if(arr[i][j]<key){
			i++;
		}else if(arr[i][j]>key){
			j--;
		}else{
			break;
		}
	}

	if(arr[i][j] == key){
		cout << key <<" found at index [" << i << ", " << j << "]" << endl; 
	}else{
		cout << key << " not found!" << endl;
	}


} 

int main(){
	int m, n;
	cin >> m >> n;

	int arr[100][100];

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j]; 
		}
	} 

	int key;
	cin >> key; 

	search_element_2d_array_sort(arr, m, n, key);

	return 0;
}