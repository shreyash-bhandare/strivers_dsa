#include<bits/stdc++.h>
using namespace std;

int maxOnes(vector<int> &nums){
    int maxi = 0;
    int curr = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1) curr++;
        else curr = 0;
        if(maxi < curr) maxi = curr;
    }
    return maxi;
}

int main(){
    vector<int> nums = {0, 1, 1, 0, 1, 1, 1, 0, 1, 1};
    cout<<maxOnes(nums);
    return 0;
}