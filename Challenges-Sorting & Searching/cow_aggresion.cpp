#include <iostream>
#include <algorithm>
using namespace std;

bool  canPosCow(int stallPos[], int stall, int cows, int curr_min){

	int last_cow = stallPos[0];
	int countCow = 1;

	for(int i=1; i<stall; i++){
		if(stallPos[i]-last_cow >= curr_min){
			last_cow = stallPos[i];
			
			countCow++;

			if(countCow == cows){
				return true;
			}
		}
	}

	return false;
}

int max_dist_cow_pos(int stallPos[], int stall, int cows){

	int s = 0;
	int e = stallPos[stall - 1] - stallPos[0];
	int ans =  0;

	while(s<=e){
		int mid = (s+e)/2;

		if(canPosCow(stallPos, stall, cows, mid)){
			ans = mid;
		    s = mid + 1;
		}else{

			e = mid - 1;
		}
	}

	return ans;

}

int main(){

	int stall, cows;
	cin >> stall >> cows;

	int stallPos[100000];

	for(int i=0; i<stall; i++){
		cin >> stallPos[i];
	}

	sort(stallPos, stallPos+stall);

	cout << max_dist_cow_pos(stallPos, stall, cows) << endl;


	return 0;
}