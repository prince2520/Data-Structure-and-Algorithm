#include <iostream>
#include <list>
using namespace std;

int main(){
	list <string> l2{"apple", "guava", "mango", "banana"};

	l2.push_back("pineapple");

	l2.sort();

	l2.reverse();

	l2.pop_front();

	l2.push_front("kiwi");

	l2.pop_back();

	for(auto it=l2.begin(); it!=l2.end(); it++){
		cout << (*it) << " -> ";
	}

	cout << endl;

	for(string s:l2){
		cout << s << " --> ";
	}

	cout << endl;
	l2.push_back("orange");
	l2.push_back("lemon");

	for(string s:l2){
		cout << s << " --> ";
	}
	cout << endl;

	/*string f;
	cin >> f;*/

	//l2.remove(f);
	for(string s:l2){
		cout << s << " --> ";
	}
	cout << endl;


	auto it = l2.begin();
	it++;

	l2.erase(it);

	for(string s:l2){
		cout << s << " --> ";
	}
	cout << endl;


	it = l2.begin();
	it++;
	it++;

	l2.insert(it,"FruitJuice");

	for(string s:l2){
		cout << s << " --> ";
	}
	cout << endl;



	

	return 0;
}