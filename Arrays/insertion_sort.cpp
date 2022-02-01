#include <iostream>
using namespace std;

// Insertions Sort 

void insertion_sort( int a[], int  n){

    for(int i=1; i <= n-1 ; i++) {
        //place the current element at 'right' position in the sorted part
        int e = a[i];

        int j = i-1;
        while (j >= 0 && a[j] > e) {
            a[j + 1] = a[j];
            j = j - 1; 
        }
        a[j + 1] = e;
        
    }

}


int main() {

    int n, key;
    cin >> n ;

    int a[1000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }


    insertion_sort(a, n);

     for(int i=0; i < n; i++){
        cout << a[i] << " ,";
    }

    return 0;

}