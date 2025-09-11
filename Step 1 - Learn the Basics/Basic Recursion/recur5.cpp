// print N to 1 without i-1
// Backtracking!
#include<bits/stdc++.h>
using namespace std;

void print(int i){
    if(i > 10) return;
    print(i+1);
    cout<<i<<" ";
}

int main(){
    print(1);
    return 0;
}