// Print the first subsequence with sum = K

#include<bits/stdc++.h>
using namespace std;

int print_subseq_k(int ind, int arr[], int n, int s, int k){
    // Small Optimization:
    // The following base case will be applicable when array contains only positive integers.
    // if(s > k) return 0;
    // But here, I'm considering the array has negative integers too.
    if(ind == n){
        // condition satisfied
        if(s == k) return 1;
        // condition not satisfied
        return 0;
    }
    // pick a particular index in the subsequence
    s += arr[ind];
    int left_recursion = print_subseq_k(ind+1, arr, n, s, k);
    s -= arr[ind];
    
    // don't pick a particular index in the subsequence
    int right_recursion = print_subseq_k(ind+1, arr, n, s, k);
    return left_recursion + right_recursion;
}

// Time Complexity: O(2^N)

int main(){
    vector<int> ds;
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;        // sum of the subsequence
    int k = 2;          // to be found sum from subsequence
    cout<<"The Count of Subarrays with Sum "<<k<<" are "<<print_subseq_k(0, arr, n, sum, k)<<endl;
    return 0;
}