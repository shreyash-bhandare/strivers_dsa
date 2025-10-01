#include<bits/stdc++.h>
using namespace std;

// with map
vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    for(int i = 0; i<nums.size(); i++){
        int a = nums[i];
        int more = target-a;

        if(mp.find(more) != mp.end()){
            return {mp[more], i};
        }
        mp[a] = i;
    }
    return {};
}
// time complexity: O(N*log(N)) space complexity: O(N) for map

// 2 - pointer approach with sorting

// vector<int> twoSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     int left = 0, right = n-1;
//     sort(nums.begin(), nums.end());
//     while(left < right){
//         if(nums[left] + nums[right] == target) return {left, right};
//         if(nums[left] + nums[right] > target) right--;
//         else{
//             left++;
//         }
//     }
//     return {-1};
// }

int main(){
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> ans1 = twoSum(nums1, target1);
    cout << "Test 1: ";
    for(int x : ans1) cout << x << " ";
    cout << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> ans2 = twoSum(nums2, target2);
    cout << "Test 2: ";
    for(int x : ans2) cout << x << " ";
    cout << endl;

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> ans3 = twoSum(nums3, target3);
    cout << "Test 3: ";
    for(int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}