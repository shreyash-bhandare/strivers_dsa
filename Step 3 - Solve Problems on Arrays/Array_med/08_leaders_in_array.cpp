#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &nums){
    int largest = INT_MIN;
    vector<int>ans;
    for(int i = nums.size()-1; i >= 0; i--){
        if(nums[i]>largest){
            largest=nums[i];
            ans.push_back(nums[i]);
        }
    }
    return ans; // we will get the answer in sorted fashion.
    // if they ask you to give according to the order of the array, just reverse it.
}

int main(){
    // Test Case 1
    vector<int> nums1 = {10,22,12,3,0,6};

    cout << "Test Case 1 Array: ";

    for(int x : nums1){
        cout << x << " ";
    }

    cout << endl;

    vector<int> ans1 = leaders(nums1);

    reverse(ans1.begin(), ans1.end());

    cout << "Leaders: ";

    for(int x : ans1){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 2
    vector<int> nums2 = {4,7,1,0};

    cout << "Test Case 2 Array: ";

    for(int x : nums2){
        cout << x << " ";
    }

    cout << endl;

    vector<int> ans2 = leaders(nums2);

    reverse(ans2.begin(), ans2.end());

    cout << "Leaders: ";

    for(int x : ans2){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 3
    vector<int> nums3 = {1,2,3,4,5};

    cout << "Test Case 3 Array: ";

    for(int x : nums3){
        cout << x << " ";
    }

    cout << endl;

    vector<int> ans3 = leaders(nums3);

    reverse(ans3.begin(), ans3.end());

    cout << "Leaders: ";

    for(int x : ans3){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 4
    vector<int> nums4 = {5,4,3,2,1};

    cout << "Test Case 4 Array: ";

    for(int x : nums4){
        cout << x << " ";
    }

    cout << endl;

    vector<int> ans4 = leaders(nums4);

    reverse(ans4.begin(), ans4.end());

    cout << "Leaders: ";

    for(int x : ans4){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 5
    vector<int> nums5 = {100};

    cout << "Test Case 5 Array: ";

    for(int x : nums5){
        cout << x << " ";
    }

    cout << endl;

    vector<int> ans5 = leaders(nums5);

    reverse(ans5.begin(), ans5.end());

    cout << "Leaders: ";

    for(int x : ans5){
        cout << x << " ";
    }

    cout << endl << endl;

    return 0;
}