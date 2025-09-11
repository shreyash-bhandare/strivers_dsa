// print 1 to N but without i+1
// Backtracking!
#include<bits/stdc++.h>
using namespace std;

void print(int i){
    if(i < 1) return;
    print(i-1);
    cout<<i<<" ";
}

int main(){
    print(5);
    return 0;
}