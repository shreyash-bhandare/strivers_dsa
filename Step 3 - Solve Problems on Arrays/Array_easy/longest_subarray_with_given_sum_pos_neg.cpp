#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> nums1 = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k1 = 6;
    cout << longestSubarray(nums1, k1) << endl;

    vector<int> nums2 = {10, -1, 2, 7, 1, 9};
    int k2 = 15;
    cout << longestSubarray(nums2, k2) << endl;

    vector<int> nums3 = {1, 2, 3};
    int k3 = 7;
    cout << longestSubarray(nums3, k3) << endl;
    return 0;
}