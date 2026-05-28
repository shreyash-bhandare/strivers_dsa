// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Example 1:
// Input: nums = [3,2,3]
// Output: [3]

// Example 2:
// Input: nums = [1]
// Output: [1]

// Example 3:
// Input: nums = [1,2]
// Output: [1,2]

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(cnt1 == 0 && el2 != nums[i]){
            el1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && el1 != nums[i]){
            el2 = nums[i];
            cnt2 = 1;
        }
        else if(el1 == nums[i]) cnt1++;
        else if(el2 == nums[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    // verify manually
    cnt1 = 0;
    cnt2 = 0;
    for(int n : nums){
        if(n == el1){
            cnt1++;
        }
        else if(n == el2){
            cnt2++;
        }
    }
    vector<int> ans;
    int mini = nums.size()/3;
    if(cnt1 > mini){
        ans.push_back(el1);
    }
    if(cnt2 > mini){
        ans.push_back(el2);
    }
    return ans;
}

int main(){
    // Test Case 1
    vector<int> nums1 = {3,2,3};
    cout << "Test Case 1 Array: ";
    for(int x : nums1){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans1 = majorityElement(nums1);
    cout << "Majority Elements (> n/3 times): ";

    for(int x : ans1){
        cout << x << " ";
    }
    cout << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1};
    cout << "Test Case 2 Array: ";
    for(int x : nums2){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans2 = majorityElement(nums2);
    cout << "Majority Elements (> n/3 times): ";

    for(int x : ans2){
        cout << x << " ";
    }
    cout << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1,2};
    cout << "Test Case 3 Array: ";
    for(int x : nums3){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans3 = majorityElement(nums3);
    cout << "Majority Elements (> n/3 times): ";

    for(int x : ans3){
        cout << x << " ";
    }
    cout << endl << endl;

    // Test Case 4
    vector<int> nums4 = {1,1,1,3,3,2,2,2};
    cout << "Test Case 4 Array: ";
    for(int x : nums4){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans4 = majorityElement(nums4);
    cout << "Majority Elements (> n/3 times): ";

    for(int x : ans4){
        cout << x << " ";
    }
    cout << endl << endl;

    // Test Case 5
    vector<int> nums5 = {2,2,9,3,9,3,9,3,9,3,9,3,9};
    cout << "Test Case 5 Array: ";
    for(int x : nums5){
        cout << x << " ";
    }
    cout << endl;
    vector<int> ans5 = majorityElement(nums5);
    cout << "Majority Elements (> n/3 times): ";

    for(int x : ans5){
        cout << x << " ";
    }
    cout << endl << endl;
    return 0;
}