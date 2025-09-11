#include<bits/stdc++.h>
using namespace std;

// List is same as vector just it gives operations such as push_back and emplace_back. 
// Rest of the operations are same as Vector

void explainList(){
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(5);
    ls.push_front(3);
    ls.emplace_front(6);

    for(auto l : ls){
        cout<<l<<" ";
    }
}

int main(){
    explainList();
    return 0;
}