// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
// For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 
// 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Example 2:
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

// Example 3:
// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        // we need to eliminate the sorted half
        // check if left half is sorted
        if(nums[low] <= nums[mid]){
            ans = min(ans, min(nums[low], nums[mid]));
            low = mid+1;
        }
        // if right half is sorted
        else{
            ans = min(ans, min(nums[mid], nums[high]));
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int mini = findMin(nums);
    cout << "Array: [ ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
    cout<<"The minimum element: "<<mini<<endl;
    return 0;
}