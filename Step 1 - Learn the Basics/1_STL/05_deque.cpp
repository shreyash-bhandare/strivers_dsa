#include<bits/stdc++.h>

using namespace std;

void printDq(deque<int> dq){
    for(int i = 0; i < dq.size(); i++){
        cout << dq[i] << " ";
    }
    cout << endl;
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1);
    printDq(dq);
    dq.emplace_back(2);
    printDq(dq);
    dq.push_front(0);
    printDq(dq);
    dq.emplace_front(-1);
    printDq(dq);
    dq.pop_back();
    printDq(dq);
    dq.pop_front();
    printDq(dq);
    dq.back();
    dq.front();
}

int main(){
    explainDeque();
    return 0;
}