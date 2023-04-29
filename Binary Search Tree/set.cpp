#include <iostream>
#include <set>
using namespace std;

int main(){
	int arr[] = {30, 20, 10, 10, 50, 60};
	int n = sizeof(arr) / sizeof(int);

	set <int> s;

	for(int i=0; i<n; i++){
		s.insert(arr[i]);
	}

	s.erase(60);

	auto it = s.find(50);
	s.erase(it);

	for(auto it = s.begin(); it!=s.end(); it++){
		cout << *(it) << " ";
	}
	cout << endl;	

	return 0;
}