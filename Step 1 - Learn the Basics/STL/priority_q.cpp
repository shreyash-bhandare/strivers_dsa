#include<bits/stdc++.h>

using namespace std;

void explainPQ(){
    // maximum element stays at the top.
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.emplace(8);
    // now the pq is: 8, 5, 2.
    cout << pq.top() << endl; // prints 8
    pq.pop(); //topmost element is popped.
    cout << pq.top() << endl; // prints 5

    //now to store in descending order,
    priority_queue<int, vector<int>, greater<int>> newpq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(4);

    cout<<pq.top();

    //time complexities: 
    // push: O(logn)
    // pop: O(logn)
    // top: O(1)
}

int main(){
    explainPQ();
    return 0;
}