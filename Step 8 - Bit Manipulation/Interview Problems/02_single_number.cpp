// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:
// Input: nums = [1]
// Output: 1

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for(int i = 0; i < nums.size(); i++){
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main(){
    vector<int> nums1 = {2, 2, 1};
    cout << "The array is: ";
    for(int num : nums1) cout << num << " ";
    cout << endl;
    cout << "The single number is: " << singleNumber(nums1) << endl;

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "The array is: ";
    for(int num : nums2) cout << num << " ";
    cout << endl;
    cout << "The single number is: " << singleNumber(nums2) << endl;

    vector<int> nums3 = {7, 3, 5, 3, 5};
    cout << "The array is: ";
    for(int num : nums3) cout << num << " ";
    cout << endl;
    cout << "The single number is: " << singleNumber(nums3) << endl;
    return 0;
}