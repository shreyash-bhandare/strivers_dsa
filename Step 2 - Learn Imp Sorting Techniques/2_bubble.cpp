#include<bits/stdc++.h>
using namespace std;

// Push max. element to the last by swapping adjacent elements

void bubble(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){                 // run n-1 passes
        int didSwap = 0;
        for(int j = 0; j < n-i-1; j++){           // compare till n-i-1
            if(arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]);
                didSwap = 1;
        }
        if(didSwap == 0) break;
        cout<<"runs\n";
    }
}


int main(){
    vector<int> q = {13, 46, 24, 52, 20, 9};
    bubble(q);
    for(int i : q){
        cout<<i<<" ";
    }
    return 0;
}