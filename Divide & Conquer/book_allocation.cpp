#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[1000], int books, int student, int current_min){
	
	int sum_of_pages_by_student = 0;
	int studCount  = 1;

	for(int i=0; i<books; i++){
		if(sum_of_pages_by_student + arr[i] > current_min){
			
			sum_of_pages_by_student = arr[i];

			studCount++;

			if(studCount > student){
				return false;
			}

		}else{
			sum_of_pages_by_student+= arr[i];
		}
	}

	return true;

}

int findPages(int arr[1000], int books, int student){
	int sum = 0;

	if(books<student){
		return -1;
	}

	for(int i=0; i<books; i++){
		sum += arr[i];
	}

	int s = 0;
	int e = sum;
	int ans = INT_MAX;

	while(s<=e){
		int mid = (s+e)/2;

		if(isPossible(arr, books, student, mid)){
			ans = min(ans, mid);
			e = mid - 1;
		}else{
			s = mid + 1; 
		}
	}

	return ans;


}

int main(){

	int t;
	cin >> t;

	for(int i=0; i<t; t++){
		int books, student;
		cin >> books >> student;

		int arr[1000];

		for(int j=0; j<books; j++){
			cin >> arr[j];
		}

		cout << findPages(arr, books, student) << endl;

	}

	return 0;
}