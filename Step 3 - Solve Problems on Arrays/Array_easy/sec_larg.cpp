// SECOND LARGEST ELEMENT IN AN ARRAY.
// Given an array of integers nums, return the second-largest element in the array. 
// If the second-largest element does not exist, return -1.

#include<bits/stdc++.h>
using namespace std;

int sec_large(vector<int> nums){
    int max = nums[0];
    int sec = INT_MIN;
    for(int i = 1; i < nums.size(); i++){
        if(max < nums[i]){
            sec = max;
            max = nums[i];
        }
        else{
            if(sec < nums[i] && max > nums[i]){
                sec = nums[i];
            }
        }
    }
    return (sec == INT_MIN) ? -1 : sec;
}

int main(){
    vector<int> quest = {8, 8, 7, 6, 5};
    cout<<sec_large(quest);
    return 0;
}