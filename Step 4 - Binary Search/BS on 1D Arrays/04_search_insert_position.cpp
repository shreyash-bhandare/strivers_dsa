// Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    // this is the question of lower_bound
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main(){
    vector<int> nums = {1,2,3,3,5,8,8,9,10,10,11};
    int target = 9;
    int ans = searchInsert(nums, target);
    cout<<"The target "<<target<<" in array: ";
    cout<<"[ ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<"], found/to be inserted at index "<<ans<<endl;
    return 0;
}