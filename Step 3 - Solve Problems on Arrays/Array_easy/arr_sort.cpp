// 1752. Check if Array Is Sorted and Rotated

// Given an array nums, return true if the array was originally sorted in non-decreasing order,
// then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length 
// such that B[i] == A[(i+x) % A.length] for every valid index i.

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int n = nums.size();
    int start;
    for(start = 1; start < n; start++){
        if(nums[start] < nums[start-1]) break;
    }
    if(start == n) return true;
    for(int j = start+1; j < n; j++){
        if(nums[j] < nums[j-1]) return false;
    }
    for(int j = 0; j < start; j++){
        if(nums[j] < nums[j-1]) return false;
    }
    return true;
}

int main(){
    vector<int> nums = {3,4,5,1,2};
    bool flag = check(nums);
    cout<<(flag ? "Array is sorted or rotated." : "Array is neither sorted nor rotated.");
    return 0;
}