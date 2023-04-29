#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	unordered_map<string, vector<string>> phonebook;

	phonebook["Rahul"].push_back("9110");
	phonebook["Rahul"].push_back("9111");
	phonebook["Rahul"].push_back("9114");
	phonebook["Rahul"].push_back("9115");

	phonebook["Priya"].push_back("8110");
	phonebook["Priya"].push_back("8111");
	phonebook["Priya"].push_back("8112");
	phonebook["Priya"].push_back("8113");


	for(auto p: phonebook){
		cout << p.first << " -> ";
		for(auto n:p.second){
			cout << n << ", ";
		}
		cout << endl;
	}

	string name;
	cin >> name;

	if(phonebook.count(name) == 0){
		cout << "Absent" << endl;
	}else{
		cout << name  << " -> ";
		for(auto p: phonebook[name]){
			cout << p << " ";
		}
		cout << endl;
	}






	return 0;
}