#include<bits/stdc++.h>
using namespace std;

// selects min. element from array and swaps it with it's correct index position.

void selection(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int minIdx = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// time complexity: ~ O(N^2)

int main(){
    vector<int> q = {13, 46, 24, 52, 20, 9};
    selection(q);
    for(int i : q){
        cout<<i<<" ";
    }
    return 0;
}