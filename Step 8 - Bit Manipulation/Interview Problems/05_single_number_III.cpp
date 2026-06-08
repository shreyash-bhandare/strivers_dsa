// Given an integer array nums, in which exactly two elements appear only once and all the other elements 
// appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// Example 1:
// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

// Example 2:
// Input: nums = [-1,0]
// Output: [-1,0]

// Example 3:
// Input: nums = [0,1]
// Output: [1,0]

#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    // nums[] = {2,4,2,14,3,7,7,3}
    int n = nums.size();
    long xorr = 0;
    for(int i = 0; i < n; i++){
        // xorr will contain 14 ^ 4 = 10
        xorr = xorr ^ nums[i];
    }
    long x = (xorr & (xorr-1))^xorr;   // (10 & 9)^10 = 2 = 0010
    // we found the rightmost set bit. (i.e. 1st)
    // now based on that bit, we will put all the numbers into 2 buckets
    // b1 = 1st bit is set
    // b2 = 1st bit is not set.
    int b1 = 0, b2 = 0;
    for(int i = 0; i < n; i++){
        if((x & nums[i]) != 0) b1 = b1^nums[i];     // we will get 14 here as 1st bit is set
        else b2 = b2^nums[i];                       // we will get 4 here as 1st bit is not set
    }
    return {b1, b2};
    
}

int main(){
    vector<int> nums1 = {1, 2, 1, 3, 2, 5};
    cout << "The array is: ";
    for(int num : nums1) cout << num << " ";
    cout << endl;
    vector<int> ans1 = singleNumber(nums1);
    cout << "The two single numbers are: " << ans1[0] << " " << ans1[1] << endl;

    vector<int> nums2 = {2, 4, 2, 14, 3, 7, 7, 3};
    cout << "The array is: ";
    for(int num : nums2) cout << num << " ";
    cout << endl;
    vector<int> ans2 = singleNumber(nums2);
    cout << "The two single numbers are: " << ans2[0] << " " << ans2[1] << endl;

    vector<int> nums3 = {-1, 0, -1, 5};
    cout << "The array is: ";
    for(int num : nums3) cout << num << " ";
    cout << endl;
    vector<int> ans3 = singleNumber(nums3);
    cout << "The two single numbers are: " << ans3[0] << " " << ans3[1] << endl;
    return 0;
}