// Print the first subsequence with sum = K

#include<bits/stdc++.h>
using namespace std;

bool print_subseq_k(int ind, vector<int> &ds, int arr[], int n, int s, int k){
    if(ind == n){
        // condition satisfied
        if(s == k){
            for(int i : ds){
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        // condition not satisfied
        return false;
    }
    // pick a particular index in the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    if(print_subseq_k(ind+1, ds, arr, n, s, k) ==  true) return true;
    ds.pop_back();
    s -= arr[ind];
    
    // don't pick a particular index in the subsequence
    if(print_subseq_k(ind+1, ds, arr, n, s, k) == true) return true;
    return false;
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