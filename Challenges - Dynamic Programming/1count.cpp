#include <iostream>
#include <climits>
using namespace std;

int count1(int *arr, int i, int n, int f){
	// Base case
	if(i == n)
		return 0;

	// Rec case
	int max_one = 0;
	int curr_one = 0;

	int case1, case2;
	case1 = case2 = INT_MIN;

	if(arr[i] == 1){
		curr_one += 1 + count1(arr, i+1, f);
	}else{
		if(f>0){
			curr_one+= 1 + count1(arr, n,  i+1, f-1);
		}else{
			curr_one = 0 + count1(arr, n, i+1, f-1);
		}
	}

}

int main(){
	int n, k;
	cin >> n >> k;

	int arr[1000] = {0};

	for(int i=0; i<n; i++)
		cin >> arr[i];

	cout << count1(arr, 0, n, k) << endl;

	return 0;
}