// Print the all subsequences with sum = K

#include<bits/stdc++.h>
using namespace std;

void print_subseq_k(int ind, vector<int> &ds, int arr[], int n, int s, int k){
    if(ind == n){
        if(s == k){
            for(int i : ds){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // pick a particular index in the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    print_subseq_k(ind+1, ds, arr, n, s, k);
    ds.pop_back();
    s -= arr[ind];
    
    // don't pick a particular index in the subsequence
    print_subseq_k(ind+1, ds, arr, n, s, k);
}

int main(){
    vector<int> ds;
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;        // sum of the subsequence
    int k = 2;          // to be found sum from subsequence
    cout<<"The Expected Sum is: "<<k<<endl;
    cout<<"The Subarrays are: "<<endl;
    print_subseq_k(0, ds, arr, n, sum, k);
    return 0;
}