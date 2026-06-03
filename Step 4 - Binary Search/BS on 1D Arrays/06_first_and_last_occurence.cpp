// Given an array of integers nums sorted in non-decreasing order, 
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

#include<bits/stdc++.h>
using namespace std;

// int lowerBound(vector<int>& nums, int target){
//     int ans = nums.size();
//     int low = 0, high = nums.size()-1;
//     while(low <= high){
//         int mid = low + (high - low)/2;
//         if(nums[mid] >= target){
//             high = mid-1;
//             ans = mid;
//         }
//         else{
//             low = mid+1;
//         }
//     }
//     return ans;
// }

// int upperBound(vector<int>& nums, int target){
//     int ans = nums.size();
//     int low = 0, high = nums.size()-1;
//     while(low <= high){
//         int mid = low + (high - low)/2;
//         if(nums[mid] > target){
//             high = mid-1;
//             ans = mid;
//         }
//         else{
//             low = mid+1;
//         }
//     }
//     return ans;
// }

// vector<int> searchRange(vector<int>& nums, int target) {
//     if(lowerBound(nums, target) == nums.size() || nums[lowerBound(nums, target)] != target) return {-1,-1};
//     return {lowerBound(nums, target), upperBound(nums, target)-1};
// }

// Pure Binary Search without Lower bound and Upper Bound.
vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            first = mid;
            high = mid-1;
        }
        else if(nums[mid] > target) high = mid-1;
        else low = mid+1;
    }
    low = 0, high = nums.size()-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            last = mid;
            low = mid+1;
        }
        else if(nums[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return {first, last};
}

int main(){
    vector<int> nums = {1,2,3,3,5,8,8,8,8,9,10,10,11};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    cout << "Array: [ ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    cout << "Target = " << target << endl;
    cout << "First Occurence = " << ans[0] << endl;
    cout << "Last Occurence = " << ans[1] << endl;
    return 0;
}