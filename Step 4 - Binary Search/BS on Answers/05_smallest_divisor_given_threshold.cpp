// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, 
// divide all the array by it, and sum the division's result. 
// Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element. 
// (For example: 7/3 = 3 and 10/2 = 5).
// The test cases are generated so that there will be an answer.

// Example 1:
// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

// Example 2:
// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44

#include<bits/stdc++.h>
using namespace std;

bool sumOfDivision(vector<int>&nums, int threshold, int divisor){
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += ceil((double)nums[i]/(double)divisor);
    }
    if(threshold < sum) return true;
    return false; 
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    if(threshold == nums.size()) return high;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(sumOfDivision(nums, threshold, mid) == true) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main(){
    vector<int> nums1 = {1,2,5,9};
    int threshold1 = 6;
    cout<<"For array [ ";
    for(int n : nums1){
        cout<<n<<" ";
    }
    cout<<"] and threshold "<<threshold1<<" the smallest divisor is "<<smallestDivisor(nums1, threshold1)<<endl;

    vector<int> nums2 = {44,22,33,11,1};
    int threshold2 = 5;
    cout<<"For array [ ";
    for(int n : nums2){
        cout<<n<<" ";
    }
    cout<<"] and threshold "<<threshold2<<" the smallest divisor is "<<smallestDivisor(nums2, threshold2)<<endl;
    return 0;
}