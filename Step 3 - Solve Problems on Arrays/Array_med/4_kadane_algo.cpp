#include<bits/stdc++.h>
using namespace std;

// for printing, we are introducing start, end and tempStart.

// otherwise the algo is simple:
// iterate through the array.
// if currSum < 0 i.e. negative, then currSum = nums[i]
// else currSum += nums[i]
// if currSum > maxSum, maxSum = currSum;

int maxSubArray(vector<int>& nums){
    int maxSum = nums[0];
    int currSum = nums[0];
    int start = 0, end = 0, tempStart = 0;
    for(int i = 1; i < nums.size(); i++){
        if(currSum < 0){
            currSum = nums[i];
            tempStart = i;
        }
        else{
            currSum += nums[i];
        }
        if(currSum > maxSum){
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Maximum subarray: ";
    for(int i = start; i <= end; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return maxSum;
}

int main(){
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums1)<<endl;

    vector<int> nums2 = {5,4,-1,7,8};
    cout<<maxSubArray(nums2)<<endl;

    vector<int> nums3 = {1};
    cout<<maxSubArray(nums3)<<endl;

    return 0;
}