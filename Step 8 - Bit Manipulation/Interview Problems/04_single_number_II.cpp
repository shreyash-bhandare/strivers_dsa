// Given an integer array nums where every element appears three times except for one, which appears exactly once. 
// Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,3,2]
// Output: 3

// Example 2:
// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

#include<bits/stdc++.h>
using namespace std;

int singleNumber2(vector<int>& nums) {
    int ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++){
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int main(){
    vector<int> nums1 = {2, 2, 3, 2};
    cout << "The array is: ";
    for(int num : nums1) cout << num << " ";
    cout << endl;
    cout << "The single number is: " << singleNumber2(nums1) << endl;

    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "The array is: ";
    for(int num : nums2) cout << num << " ";
    cout << endl;
    cout << "The single number is: " << singleNumber2(nums2) << endl;

    vector<int> nums3 = {5, 7, 5, 5, 7, 7, 10};
    cout << "The array is: ";
    for(int num : nums3) cout << num << " ";
    cout << endl;
    cout << "The single number is: " << singleNumber2(nums3) << endl;
    return 0;
}