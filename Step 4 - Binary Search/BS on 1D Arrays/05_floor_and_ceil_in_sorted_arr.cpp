// Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. 
// The floor of x is the largest element in the array which is smaller than or equal to x. 
// The ceiling of x is the smallest element in the array greater than or equal to x. 
// If no floor or ceil exists, output -1.

// Example 1
// Input : nums =[3, 4, 4, 7, 8, 10], x= 5
// Output: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2
// Input : nums =[3, 4, 4, 7, 8, 10], x= 8
// Output: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

#include<bits/stdc++.h>
using namespace std;

// finding largest element <= target
int findFloor(vector<int>&nums, int target){
    int ans = -1;
    int low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] <= target){
            ans = nums[mid];
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

// finding the smallest element >= target
int findCeil(vector<int>&nums, int target){
    int low = 0, high = nums.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= target){
            ans = nums[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    return {findFloor(nums, x), findCeil(nums, x)};
}

int main(){
    vector<int> nums = {1,2,3,3,5,8,8,9,10,10,11};
    int target = 7;

    vector<int> ans = getFloorAndCeil(nums, target);

    cout << "Array: [ ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    cout << "Target = " << target << endl;
    cout << "Floor = " << ans[0] << endl;
    cout << "Ceil  = " << ans[1] << endl;
    return 0;
}