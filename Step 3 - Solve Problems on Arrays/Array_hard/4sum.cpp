// Given an array nums of n integers, return an array of all the unique quadruplets 
// [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     set<vector<int>> st;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             for(int k = j+1; k < n; k++){
//                 for(int l = k+1; l < n; l++){
//                     long long sum = nums[i] + nums[j];
//                     sum += nums[k];
//                     sum += nums[l];                     // to avoid integer to long long typecasting limit.
//                     if(sum == target){
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// Time Complexity: O(N^4)
// Space Complexity: 2 * O(No. of Quads) for set and vector

// BETTER APPROACH SAME AS 3 SUM'S BETTER APPROACH

// OPTIMAL SOLUTION
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}

// Time Complexity: O(N^2 * N) N^2 - for loops, N - while loop
// Space Complexity: O(No. of Quads)

int main(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "Input Array: [ ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << "]\n";
    cout << "Target = " << target << "\n\n";
    cout << "Output:\n";
    for(auto quad : ans) {
        cout << "[ ";
        for(int num : quad) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}