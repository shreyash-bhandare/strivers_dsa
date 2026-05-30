#include<bits/stdc++.h>

using namespace std;

void explainQ(){
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.emplace(3);

    Q.back() += 4;
    cout<<Q.back();
    cout<<endl;
    cout<<Q.front();
    cout<<endl;
    Q.pop();
    cout<<Q.front();
}

int main(){
    explainQ();
    return 0;
}