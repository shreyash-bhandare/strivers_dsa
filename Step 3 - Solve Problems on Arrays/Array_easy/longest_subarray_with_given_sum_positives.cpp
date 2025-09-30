#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k){
    long long sum = nums[0];
    int n = nums.size();
    int left = 0, right = 0;
    int maxLen = 0;
    
    while(right < n){
        while(sum > k && left <= right){
            sum -= nums[left];
            left++;
        }
        if(sum == k) maxLen = max(maxLen, right-left+1);
        right++;
        if(right < n) sum += nums[right];
    }
    return maxLen;    
}

int main(){
    vector<int> nums1 = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k1 = 6;
    cout << longestSubarray(nums1, k1) << endl;

    vector<int> nums2 = {10, 5, 2, 7, 1, 9};
    int k2 = 15;
    cout << longestSubarray(nums2, k2) << endl;

    vector<int> nums3 = {1, 2, 3};
    int k3 = 7;
    cout << longestSubarray(nums3, k3) << endl;

    return 0;
}