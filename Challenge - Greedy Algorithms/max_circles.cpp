#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define ll long long

class circle{
public:
	ll  startXCoordinate, endXCoordinate;

	circle(int s, int e){
		startXCoordinate = s;
		endXCoordinate = e;
	}
};

bool compare(circle c1, circle c2){
	return  c1.endXCoordinate < c2.endXCoordinate;
}

ll max_circle( vector<circle>  c, int n){

	ll ans = 0;

	ll endingX = INT_MIN;
	
	for(int i=0; i<n; i++){
		if(endingX<=c[i].startXCoordinate){
			ans+=1;
			endingX = c[i].endXCoordinate;
		}
	}

	return ans;

}

int main(){
	int n;
	cin >> n;

	vector<circle> v;

	ll x, r;

	for(int i=0; i<n; i++){
		cin >> x >> r;

		circle c( x-r, x+r);
		v.push_back(c);
	}

	sort(v.begin(), v.end(), compare);


    cout << n- max_circle(v, n) << endl; 



	return 0;
}