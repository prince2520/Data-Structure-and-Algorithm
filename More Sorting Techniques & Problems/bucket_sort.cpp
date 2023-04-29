#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
	int marks;
	string name;
};

void bucket_sort(Student s[], int n){

	vector<Student> v[101];

	for(int i=0; i<n; i++){
		int marks = s[i].marks;

		v[marks].push_back(s[i]);
	}

	for(int i=100; i>=0; i--){
		for(auto it=v[i].begin(); it!=v[i].end(); it++){
			cout << (*it).marks << " " << (*it).name <<endl;
		}
	}

}

int main(){

	Student s[100];
	int n;
	cin >> n;

	for(int i=0; i < n; i++){
		cin >> s[i].marks >> s[i].name; 
	}
	bucket_sort(s, n);
	

	return 0;
}