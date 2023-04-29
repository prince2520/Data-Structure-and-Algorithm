#include <iostream>
using namespace std;

int main() {

    int a[100][100] = {0};
    int m, n;
    int val = 1; 
    cin >> m >> n ;


    for(int row = 0; row <= m-1; row++ ){
        for(int col = 0; col <= n - 1; col++){
            a[row][col] = val;
            val = val + 1;
            cout << a[row][col] << " ";
        } 
        cout << endl;
    }

    int startRow = 0;
    int endRow = m-1;
    int startCol = 0; 
    int endCol = n-1;

    while(startRow <= endRow){
        for(int i=startCol; i <= endCol; i++){
            cout << a[startRow][i] << " ";
        }
        startRow++;

        for(int i=startRow; i <= endRow; i++){
            cout << a[i][endCol] << " ";
        }
        endCol--;

        if(startRow<endRow){
         for(int i=endCol; i >= startCol; i--){
             cout << a[endRow][i] << " ";
         }
          endRow--;
        }
        
        if(endCol > startCol){
            for(int i=endRow; i >= startRow; i--){
            cout << a[i][startCol] << " ";
        }
        startCol++;
        }
    }

    return 0;
}