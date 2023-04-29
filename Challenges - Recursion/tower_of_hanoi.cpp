#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char src, char helper, char dest){
	// Base case
	if(n == 0){
		return;
	}

	// Rec case

	tower_of_hanoi(n-1, src, dest , helper);

	cout << "Moving ring " << n<< " from "<< src <<  " to " << dest << endl;

	tower_of_hanoi(n-1, helper, src, dest);


}

int main(){
	int n;
	cin >> n;

	tower_of_hanoi(n, 'A', 'C', 'B');

	return 0;
}