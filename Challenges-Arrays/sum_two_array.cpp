#include <iostream>
#include <cmath>

using namespace std;

void get_array_value(int arr[1000], int size){
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
}

void sum_two_array(int arr1[1000], int size1, int arr2[1000], int size2){
	int i=size1-1;
	int j=size2-1;
	int k=0;

	int carry=0;
	int sumArr[size2] = {0};

	while(j>=0){
		int sum = 0;

		
		if(i>=0){
			sum = (arr1[i] + arr2[j] + carry)%10 ;
			carry = floor((arr1[i] + arr2[j] + carry)/10);
		}else{
			sum = (arr2[j] + carry)%10;
		    carry = floor((arr2[j] + carry)/10);
		}

		sumArr[k] = sum;

		j--;
		i--;
		k++;
	}

	int l = size2-1;

	if(carry > 0){
		sumArr[size2]=carry;
		l = size2;
	}

	for(; l>=0; l--){
		cout << sumArr[l] << ", ";
	}

	cout << "END" << endl;
}

int main(){
	int size1;
	cin >> size1;

	int arr1[1000];
	get_array_value(arr1, size1);

	int size2;
	cin >> size2;

	int arr2[1000];
	get_array_value(arr2, size2);


	sum_two_array(arr1, size1, arr2, size2);



	return 0;
}