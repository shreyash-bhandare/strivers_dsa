// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

#include<bits/stdc++.h>
using namespace std;

void findSubset(int ind, vector<int>&nums, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);
    for(int i = ind; i < nums.size(); i++){
        if(i != ind && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        findSubset(i+1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubset(0, nums, ds, ans);
    return ans;
}

int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    cout<<"The subsests of array: ";
    for(int i : nums){
        cout<<i<<" ";
    }
    cout<<"are: "<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<"[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
    return 0;
}