#include<bits/stdc++.h>
using namespace std;

void rec_insert(vector<int> &arr, int n){
    if(n <= 1) return;
    rec_insert(arr, n-1);

    int last = arr[n-1];            // taking the last element of the array to insert it into its correct position.
    int j = n-2;                    // index of the selected last element.

    while(j >= 0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = last;                // inserting the element at its correct position.
}

int main(){
    vector<int> q = {13, 46, 24, 52, 20, 9};
    rec_insert(q, q.size());
    for(int i : q){
        cout<<i<<" ";
    }
    return 0;
}