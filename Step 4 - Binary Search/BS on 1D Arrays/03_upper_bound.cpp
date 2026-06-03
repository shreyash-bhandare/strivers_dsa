// Upper Bound = smallest Index such that nums[ind] > target.
// Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
// The upper bound of x is defined as the smallest index i such that nums[i] > x.
// If no such index is found, return the size of the array.

// Example 1
// Input : n= 4, nums = [1,2,2,3], x = 2
// Output:3
// Explanation:
// Index 3 is the smallest index such that arr[3] > x.

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;
    int ub = nums.size();
    while(low <= high){
        if(nums[mid] > target) {
            ub = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = low + (high-low)/2;
    }
    return ub;
}

int main(){
    vector<int> nums = {1,2,3,3,5,8,8,9,10,10,11};
    int target = 9;
    int ans = upperBound(nums, target);
    cout<<"The upper bound of target "<<target<<" in array: ";
    cout<<"[ ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<"], found at index "<<ans<<endl;
    return 0;
}