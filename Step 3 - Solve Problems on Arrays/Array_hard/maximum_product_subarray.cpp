// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element.

// Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n-1-i];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

int main(){
    vector<int> query = {2,3,-2,4};
    int maxi = maxProduct(query);
    cout<<"For the Array: ";
    for(int i : query){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"The maximum product is: "<<maxi<<endl;
    return 0;
}