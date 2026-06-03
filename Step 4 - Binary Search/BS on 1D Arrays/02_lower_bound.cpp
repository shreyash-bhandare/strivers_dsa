// Lower Bound = smallest Index such that nums[ind] >= target.
// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
// The lower bound algorithm finds the first and smallest index in a sorted array 
// where the value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.

// Example 1
// Input : nums= [1,2,2,3], x = 2
// Output:1
// Explanation:
// Index 1 is the smallest index such that arr[1] >= x.


#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;
    int lb = nums.size();
    while(low <= high){
        if(nums[mid] >= target) {
            lb = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    return lb;
}

int main(){
    vector<int> nums = {1,2,3,3,5,8,8,9,10,10,11};
    int target = 9;
    int ans = lowerBound(nums, target);
    cout<<"The lower bound of target "<<target<<" in array: ";
    cout<<"[ ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<"], found at index "<<ans<<endl;
    return 0;
}