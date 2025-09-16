//26. Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, 
// remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Change the array nums such that the first k elements of nums contain the unique elements in the order 
// they were present in nums initially. 
// The remaining elements of nums are not important as well as the size of nums.
// Return k.
#include<bits/stdc++.h>
using namespace std;

// brute force:
// int removeDuplicates(vector<int>& nums) {
//     int n = nums.size();
//     set<int> st;
//     for(int i = 0; i < n; i++){
//         st.insert(nums[i]);
//     }
//     int index = 0;
//     for(auto it : st){
//         nums[index] = it;
//         index++;
//     }
//     return index;
// }

// time complexity : O(NlogN + N)
// space complexity : O(N) size of set

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    for(int j = 1; j < n; j++){
        if(nums[i] != nums[j]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int> quest = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(quest);
    cout<<k<<endl;
    for(int i = 0; i < k; i++){
        cout<<quest[i]<<" ";
    }
    return 0;
}