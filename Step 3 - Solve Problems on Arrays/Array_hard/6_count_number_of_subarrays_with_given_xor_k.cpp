// Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

// Example 1
// Input : nums = [4, 2, 2, 6, 4], k = 6
// Output : 4
// Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

// Example 2
// Input :nums = [5, 6, 7, 8, 9], k = 5
// Output : 2
// Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// Get all the subarrays with 2 loops and check the XOR using third loop.
// Time Complexity: O(N^3)

// BETTER APPROACH
// Optimise brute force and use only 2 loops.
// Time Complexity: O(N^2)


int subarraysWithXorK(vector<int> &nums, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;      //(0,1)
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        xr = xr^nums[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    vector<int> quest = {4,2,2,6,4};
    int k = 6;
    int ans = subarraysWithXorK(quest, k);
    for(int q : quest){
        cout<<q<<" ";
    }
    cout<<endl;
    cout<<"The number of subarrays with given XOR "<<k<<" is: "<<ans;
    return 0;
}