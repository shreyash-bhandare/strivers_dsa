// print linearly from 1 to N
#include<bits/stdc++.h>
using namespace std;

void pRec(int i, int N){
    if(i > N) return;
    cout<<i<<" ";
    pRec(++i, N);
}

int main(){
    pRec(1, 5);
    return 0;
}