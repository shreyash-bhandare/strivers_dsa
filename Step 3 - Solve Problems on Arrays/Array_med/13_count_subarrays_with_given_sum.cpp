// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int, int>mpp;
    mpp[0] = 1;
    int n = nums.size();
    int presum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        presum += nums[i];
        int remove = presum - k;
        cnt += mpp[remove];
        mpp[presum]++;
    }
    return cnt;
}

int main(){
    // Test Case 1
    vector<int> nums1 = {1,1,1};
    int k1 = 2;
    cout << "Test Case 1 Array: ";
    for(int x : nums1){
        cout << x << " ";
    }
    cout << endl;
    cout << "k = " << k1 << endl;
    int ans1 = subarraySum(nums1, k1);
    cout << "Number of Subarrays: " << ans1 << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1,2,3};
    int k2 = 3;
    cout << "Test Case 2 Array: ";
    for(int x : nums2){
        cout << x << " ";
    }
    cout << endl;
    cout << "k = " << k2 << endl;
    int ans2 = subarraySum(nums2, k2);
    cout << "Number of Subarrays: " << ans2 << endl << endl;

    // Test Case 3
    vector<int> nums3 = {3,4,7,2,-3,1,4,2};
    int k3 = 7;
    cout << "Test Case 3 Array: ";
    for(int x : nums3){
        cout << x << " ";
    }
    cout << endl;
    cout << "k = " << k3 << endl;
    int ans3 = subarraySum(nums3, k3);
    cout << "Number of Subarrays: " << ans3 << endl << endl;

    // Test Case 4
    vector<int> nums4 = {1,-1,0};
    int k4 = 0;
    cout << "Test Case 4 Array: ";
    for(int x : nums4){
        cout << x << " ";
    }
    cout << endl;
    cout << "k = " << k4 << endl;
    int ans4 = subarraySum(nums4, k4);
    cout << "Number of Subarrays: " << ans4 << endl << endl;

    // Test Case 5
    vector<int> nums5 = {0,0,0,0};
    int k5 = 0;
    cout << "Test Case 5 Array: ";
    for(int x : nums5){
        cout << x << " ";
    }
    cout << endl;
    cout << "k = " << k5 << endl;
    int ans5 = subarraySum(nums5, k5);
    cout << "Number of Subarrays: " << ans5 << endl << endl;
    return 0;
}