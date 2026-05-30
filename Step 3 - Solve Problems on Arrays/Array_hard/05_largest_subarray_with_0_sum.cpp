// Given an array having both positive and negative integers.
// The task is to compute the lenght of the largest subarray with sum 0.

// Example 1:
// Input:
// N = 8
// A[] = {15, -2, 2, -8, 1, 7, 10, 23}
// Output: 5
// Explanation: The largest subarray with sum 0 will be -2 2 -8 1 7

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N logN) N - number of elements, log N - look up in hashmap
// Space Complexity: O(N) storing in hashmap

int maxLen(vector<int> &nums){
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum == 0){
            maxi = i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main(){
    vector<int> quest = {1,-1,3,2,-2,-8,1,7,10,23};
    int maxi = maxLen(quest);
    for(int q : quest){
        cout<<q<<" ";
    }
    cout<<endl;
    cout<<"Maximum length with sum 0 is: "<<maxi<<endl;
    return 0;
}