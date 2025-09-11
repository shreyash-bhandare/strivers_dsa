// print linearly from N to 1
#include<bits/stdc++.h>
using namespace std;

void pRec(int i, int n){
    if(i > n) return;
    cout<<n<<" ";
    pRec(i, n - 1);
}

int main(){
    pRec(1, 10);
    return 0;
}