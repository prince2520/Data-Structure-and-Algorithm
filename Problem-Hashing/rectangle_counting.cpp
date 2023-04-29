#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Point{
public:
	int x;
	int y;

	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class compare{
public:
	bool operator()(Point A, Point B){
		if(A.x == B.x){
			return A.y < B.y; 
		}

		return A.x < B.x;

	}
};

int count_rects(vector <Point> &coords){
	int n = coords.size();

	set <Point, compare> s;

	for(auto it : coords){
		s.insert(it);
	} 


	int ans = 0;

	for(auto it = s.begin(); it!= prev(s.end()); it++){
		for(auto jt = next(it); jt!= s.end(); jt++){

			Point p1 = *it;
			Point p2 = *jt;

			if(p1.x == p2.x or p1.y ==p2.y){
				continue;
			}

			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);

			if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
				ans++;
			}
		}
	}


	return ans/2;


}


int main(){
	int m;
	cin >> m;

	vector<Point> coords;

	int x, y;
	
	while(m--){
		cin >> x >> y;
		Point p(x,y);
		coords.push_back(p);
	}

	cout <<count_rects(coords) << endl;

	return 0;
}