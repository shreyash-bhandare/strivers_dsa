#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for(int i = 0; i < nums.size(); i++){
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main(){
    vector<int> nums = {2, 3, 1, 2, 3, 4, 5, 7, 5, 1, 4};
    cout<<singleNumber(nums);
    return 0;
}