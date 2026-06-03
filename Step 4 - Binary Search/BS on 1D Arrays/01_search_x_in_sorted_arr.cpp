// Given an array of integers nums which is sorted in ascending order, and an integer target, 
// write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;
    while(low <= high){
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) high = mid-1;
        if(nums[mid] < target) low = mid+1;
        mid = (low+high)/2;
    }
    return -1;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int ans = search(nums, target);
    cout<<"The target "<<target<<" in array: ";
    cout<<"[ ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<"], found at index "<<ans<<endl;

    return 0;
}