#include <iostream>
#include <map>
#include <vector> 
using namespace std;

void intersectionTwoArray(map<int, int> s1, map<int,int> s2){

	vector <int> v;

	cout << "[";

	for(auto it: s1){
		if(s2.count(it.first)!=0){
			int freq = min(s2[it.first], it.second);

			while(freq--){
				v.push_back(it.first);
			}
		}
	}

	for(auto it=v.begin(); it!= prev(v.end()); it++){
		cout << *it << ", ";
	}

	cout << v[v.size()-1];

	cout << "]";

}

int main(){
	int n;
	cin >> n;

	map <int, int> s1; // (value, frequency)
    map <int, int> s2;

	int d;

	for(int i=0; i<n; i++){
		cin >> d;
		if(s1.count(d) == 0){
			s1.insert(make_pair(d,1));
		} else{
			s1[d]+=1;
		}
	}

	for(int j=0; j<n; j++){
		cin >> d;
		if(s2.count(d) == 0){
			s2.insert(make_pair(d,1));
		} else{
			s2[d] += 1;
		}
	}

	intersectionTwoArray(s1, s2);

	return 0;
}