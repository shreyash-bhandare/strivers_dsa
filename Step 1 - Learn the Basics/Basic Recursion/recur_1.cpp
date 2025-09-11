// print name 5 times

#include<bits/stdc++.h>
using namespace std;

void pName(int i, int n){
    if(i > n) return;
    cout<<"Shreyash"<<endl;
    pName(i+1, n);
}

int main(){
    int n;
    cin>>n;
    pName(1, n);
    return 0;
}