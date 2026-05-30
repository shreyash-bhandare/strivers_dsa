// Given an array nums of n integers. Return array of sum of all subsets of the array nums.
// Output can be returned in any order.

// Example 1
// Input : nums = [2, 3]
// Output : [0, 2, 3, 5]
// Explanation :
// When no elements is taken then Sum = 0.
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then sum = 2+3 = 5.

// Example 2
// Input : nums = [5, 2, 1]
// Output : [0, 1, 2, 3, 5, 6, 7, 8]
// Explanation :
// When no elements is taken then Sum = 0.
// When only 5 is taken then Sum = 5.
// When only 2 is taken then Sum = 2.
// When only 1 is taken then Sum = 1.
// When element 2 and 1 are taken then sum = 2+1 = 3.


#include<bits/stdc++.h>
using namespace std;

void findSubset(int ind, int n, int s, vector<int> &nums, vector<int>&ans){
    if(ind == n){
        ans.push_back(s);
        return;
    }
    // pick the element
    findSubset(ind+1, n, s+nums[ind], nums, ans);

    // don't pick the element
    findSubset(ind+1, n, s, nums, ans);

}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;
    findSubset(0, nums.size(), 0, nums, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums = {3,2,1};
    vector<int> ans = subsetSums(nums);
    cout<<"The subset sum of array: ";
    for(int i : nums){
        cout<<i<<" ";
    }
    cout<<"is: ";
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}