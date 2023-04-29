#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int isPossible(int boards[], int num_boards, int painter, int time, int current_min){

	int sum =0;
	int painter_used = 1;
	
	for(int i=0; i<num_boards; i++){
		if((sum + boards[i]*time) > current_min){
			sum = boards[i]*time;

			painter_used++;

			if(painter_used>painter){
				return false;
			}

		}else{
			sum += boards[i]*time;
		}
	}

	return true;

}

int min_paint_time(int boards[], int num_boards, int painter, int time){

	int sum = 0;

	for(int i=0; i<num_boards; i++){
		sum += boards[i]*time;
	}

	int i = boards[num_boards-1] * time;
	int j = sum;
	int ans = INT_MAX;

	while(i<=j){
		
		int mid = (i+j)/2;

		if(isPossible(boards, num_boards, painter, time, mid)){
			ans = min(mid, ans);
			j = mid - 1; 
		}else{
			i = mid + 1;
		}
	}

	return ans;

}

int main(){

	int num_boards, painter, time;
	cin >> num_boards >> painter >> time;

	int boards[100000] = {0};

	for(int i=0; i<num_boards; i++){
		cin >> boards[i];
	}

	sort(boards, boards+num_boards);

	cout << min_paint_time(boards, num_boards, painter, time) << endl;

	return 0;
}