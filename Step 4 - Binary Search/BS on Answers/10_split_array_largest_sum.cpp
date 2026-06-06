// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that 
// the largest sum of any subarray is minimized.
// Return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Example 1:
// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

// Example 2:
// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

#include<bits/stdc++.h>
using namespace std;

int findSubarraySum(vector<int>&nums, int pages){
    int subarrays = 1;
    long long sumOfSubarray = 0;
    for(int i = 0; i < nums.size(); i++){
        if(sumOfSubarray + nums[i] <= pages){
            sumOfSubarray += nums[i];
        }
        else{
            subarrays++;
            sumOfSubarray = nums[i];
        }
    }
    return subarrays;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    if(k > n) return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while(low <= high){
        int mid = low + (high - low)/2;
        int sum = findSubarraySum(nums, mid);
        if(sum > k) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main(){
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    int ans1 = splitArray(nums1, k1);
    cout << "Minimum largest sum for array [ ";
    for(int num : nums1){
        cout << num << " ";
    }
    cout << "] is " << ans1 << " for " << k1 << " subarrays." << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    int ans2 = splitArray(nums2, k2);
    cout << "Minimum largest sum for array [ ";
    for(int num : nums2){
        cout << num << " ";
    }
    cout << "] is " << ans2 << " for " << k2 << " subarrays." << endl;

    vector<int> nums3 = {1, 4, 4};
    int k3 = 3;
    int ans3 = splitArray(nums3, k3);
    cout << "Minimum largest sum for array [ ";
    for(int num : nums3){
        cout << num << " ";
    }
    cout << "] is " << ans3 << " for " << k3 << " subarrays." << endl;
    return 0;
}