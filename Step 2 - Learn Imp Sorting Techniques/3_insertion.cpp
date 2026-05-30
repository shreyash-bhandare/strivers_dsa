#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main(){
    vector<int> q = {13, 46, 24, 52, 20, 9};
    insertion(q);
    for(int i : q){
        cout<<i<<" ";
    }
    return 0;
}