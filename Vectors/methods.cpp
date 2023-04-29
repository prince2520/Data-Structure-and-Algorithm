#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector <int> d{1, 2, 3, 10, 14};
	
	// Push Back O(1) for most of the time 
	d.push_back(16);

	//Pop Back / Removes the last element O(1)
	d.pop_back();

	// Insert some elements in the middle 
	d.insert(d.begin()+3, 4, 100);

	// erase some element in the middle 
	d.erase(d.begin()+2);
	d.erase(d.begin()+2, d.begin()+5);

	// size
	cout << d.size() << endl; 
	cout << d.capacity() << endl;

	//we avoid the shrink 
	d.resize(18); // id the size is increasing then more memory will be allocated
	cout << d.capacity() << endl;

	// remove all the vector , doesn't delete the memory occupied by the array
	d.clear();

	//empty
	if(d.empty()){
		cout << "This is an empty vector";
	}

	cout  << d.size() << endl;

	for(int x:d){
		cout << x << ", " ;
	}

	cout << endl;

	d.push_back(10);
	d.push_back(11);
	d.push_back(12);

	cout << d.front() << endl;
	cout << d.back() << endl;

	// Reverse 
	int n;
	cin >> n;

	vector <int> v;

	// To avoid doubling, we will use reserve function
	v.reserve(1000);

	for(int i=0; i<n; i++){
		int no;
		cin >> no; 

		v.push_back(no);

		cout << "Changing capacity: " << v.capacity() << endl;
	}

	cout << "Capacity: " << v.capacity() << endl;

	for(int x:v){
		cout << x << ", ";
	}


	return 0;
}