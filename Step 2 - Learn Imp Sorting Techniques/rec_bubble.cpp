#include<bits/stdc++.h>
using namespace std;

void rec_bubble(vector<int> &arr, int n){
    if(n == 1) return;
    bool didSwap = false;
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            didSwap = true;
        }
    }
    if(!didSwap) return;
    rec_bubble(arr, n-1);
}

int main(){
    vector<int> q = {13, 46, 24, 52, 20, 9};
    rec_bubble(q, q.size());
    for(int i : q){
        cout<<i<<" ";
    }
    return 0;
}