// Given an integer array nums of size n, sorted in ascending order with distinct values. 
// The array has been right rotated an unknown number of times, between 0 and n-1 (including). 
// Determine the number of rotations performed on the array.

// Example 1
// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
// Output: 4
// Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. 
// So, we can notice that the array has been rotated 4 times.

// Example 2
// Input: nums = [3, 4, 5, 1, 2]
// Output: 3
// Explanation: The original array should be [1, 2, 3, 4, 5]. 
// So, we can notice that the array has been rotated 3 times.

#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums)  {
    int low = 0, high = nums.size()-1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        // if array is sorted and not rotated
        if(nums[low] <= nums[high]){
            if(nums[low] <= ans){
                ans = nums[low];
                index = low;
            }
            break;
        }
        // if array is left sorted
        if(nums[low] <= nums[mid]){
            if(nums[low] <= ans){
                ans = nums[low];
                index = low;
            }
            high = mid-1;
        }
        else{
            if(nums[mid] <= ans){
                ans = nums[mid];
                index = mid;
            }
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int rotated = findKRotation(nums);
    cout << "Array: [ ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
    cout<<"The array is rotated by "<<rotated<<" places."<<endl;
    return 0;
}