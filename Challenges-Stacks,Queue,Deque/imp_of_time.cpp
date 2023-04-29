#include <iostream>
#include <queue>
using namespace std;

int imp_of_time(int *idealOrder, int n, queue<int> &callOrder){

    int time = 0;

    for(int i=0; i<n; i++){
       
        while(idealOrder[i] != callOrder.front()){
            int front = callOrder.front();
            callOrder.push(front);
            callOrder.pop();
            time += 1; 
        }

        callOrder.pop();
        time += 1;
    }

    return time;

}

int main(){
    int n;
    cin >> n;

    queue <int> callOrder;

    int d;
    for(int i=0; i<n; i++){
        cin >> d;
        callOrder.push(d);
    }

    int *idealOrder = new int[1000000];
    for(int j=0; j<n; j++){
        cin >> idealOrder[j];
    }

    cout << imp_of_time(idealOrder, n, callOrder);

    delete [] idealOrder;

    return 0;
}