#include<bits/stdc++.h>
using namespace std;

// Better Approach: O(N * log(N))
// int majorityElement(vector<int>& nums) {
//     map<int, int> mp;
//     for(int i = 0; i < nums.size(); i++){
//         mp[nums[i]]++;
//     }
//     for(auto m : mp){
//         if(m.second > nums.size()/2) return m.first;
//     }
//     return -1;
// }

// Moore's voting Algorithm:
int majorityElement(vector<int> &nums){
    int maj = 0;
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(cnt == 0) maj = nums[i];
        if(maj == nums[i]) cnt++;
        else cnt--;
    }
    return maj;
}

int main(){
    vector<int> nums = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    cout<<majorityElement(nums);
    return 0;
}