#include<bits/stdc++.h>
using namespace std;

void print_subsequence(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(int i : ds){
            cout<<i<<" ";
        }
        if(ds.size() == 0) cout<<"{}"<<endl;
        cout<<endl;
        return;
    }
    // pick a particular index in the subsequence
    ds.push_back(arr[ind]);
    print_subsequence(ind+1, ds, arr, n);
    ds.pop_back();
    // don't pick a particular index in the subsequence
    print_subsequence(ind+1, ds, arr, n);

    // For printing in the Proper Order.
    // // don't pick a particular index in the subsequence
    // print_subsequence(ind+1, ds, arr, n);

    // // pick a particular index in the subsequence
    // ds.push_back(arr[ind]);
    // print_subsequence(ind+1, ds, arr, n);
    // ds.pop_back();
}

// Time Complexity: O(N * 2^N), N for printing approx, 2^N for recursion.
// Space Complexity: O(N) for ds.

int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> ds;
    print_subsequence(0, ds, arr, n);
    return 0;
}