// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){
    int idx;
    int n = nums.size();
    for(idx = 0; idx < n; idx++){
        if(nums[idx] == 0){
            break;
        }
    }
    for(int j = idx+1; j < n; j++){
        if(nums[j] != 0){
            swap(nums[j], nums[idx]);
            idx++;
        }
    }
}

int main(){
    vector<int> nums = {1, 0, 0, 2, 0, 4, 0, 8};
    moveZeroes(nums);
    for(auto i : nums){
        cout<<i<<" ";
    }
    return 0;
}