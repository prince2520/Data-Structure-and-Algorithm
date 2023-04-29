#include <iostream>
#include<unordered_map>
#include <string>
using namespace std;

class Student{
public:
	string firstname;
	string lastname;
	int rollno;

	Student(string f, string l, int r){
		firstname = f;
		lastname = l;
		rollno = r;
	}

	bool operator==(const Student &s) const{
		return rollno == s.rollno ? true : false;
	}
};

class HashFn{
public:
	size_t operator()(const Student &s) const {
		return s.firstname.length() + s.lastname.length();
	}
};

int main(){
	Student s1("Prateek", "Narang", 10);
	Student s2("Rahul", "Kumar", 23);
	Student s3("Prateek", "Gupta", 30);
	Student s4("Rahul", "Kumar", 120);

	unordered_map<Student, int, HashFn> student_map;

	// Add Student - marks to hashmap 
	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 11;
	student_map[s4] = 45;

	// iterate over all students
	for(auto s:student_map){
		cout << s.first.firstname << " " << s.first.lastname << " and Marks: " << s.second << endl;
	}

	return 0;
}