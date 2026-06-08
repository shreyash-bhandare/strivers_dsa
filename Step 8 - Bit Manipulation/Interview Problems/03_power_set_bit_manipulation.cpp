// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int noOfSubsets = 1<<n;
    for(int num = 0; num < noOfSubsets; num++){
        vector<int> subset;
        for(int i = 0; i < n; i++){
            if(num & (1<<i)) subset.push_back(nums[i]);
        }
        ans.push_back(subset);
    }
    return ans;
}

void printSubsets(vector<vector<int>>& ans) {
    for(auto &subset : ans) {
        cout << "{ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main(){
    vector<int> nums1 = {1, 2};
    cout << "The array is: ";
    for(int num : nums1) cout << num << " ";
    cout << endl;
    cout << "The subsets are:" << endl;
    vector<vector<int>> ans1 = subsets(nums1);
    printSubsets(ans1);

    vector<int> nums2 = {1, 2, 3};
    cout << "\nThe array is: ";
    for(int num : nums2) cout << num << " ";
    cout << endl;
    cout << "The subsets are:" << endl;
    vector<vector<int>> ans2 = subsets(nums2);
    printSubsets(ans2);

    vector<int> nums3 = {5};
    cout << "\nThe array is: ";
    for(int num : nums3) cout << num << " ";
    cout << endl;
    cout << "The subsets are:" << endl;
    vector<vector<int>> ans3 = subsets(nums3);
    printSubsets(ans3);
    return 0;
}