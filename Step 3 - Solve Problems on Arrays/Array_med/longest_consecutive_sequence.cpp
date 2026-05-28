// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
        if(n == 0 || n == 1) return n;
        int longest = 1;
        unordered_set<int> st;
        for(int i : nums){
            st.emplace(i);
        }
        for(int it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
    return longest;
}

int main(){
    // Test Case 1
    vector<int> nums1 = {100,4,200,1,3,2};

    cout << "Test Case 1 Array: ";

    for(int x : nums1){
        cout << x << " ";
    }

    cout << endl;

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(nums1);

    cout << endl << endl;


    // Test Case 2
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};

    cout << "Test Case 2 Array: ";

    for(int x : nums2){
        cout << x << " ";
    }

    cout << endl;

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(nums2);

    cout << endl << endl;


    // Test Case 3
    vector<int> nums3 = {1,2,0,1};

    cout << "Test Case 3 Array: ";

    for(int x : nums3){
        cout << x << " ";
    }

    cout << endl;

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(nums3);

    cout << endl << endl;


    // Test Case 4
    vector<int> nums4 = {9,1,4,7,3,-1,0,5,8,-1,6};

    cout << "Test Case 4 Array: ";

    for(int x : nums4){
        cout << x << " ";
    }

    cout << endl;

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(nums4);

    cout << endl << endl;


    // Test Case 5
    vector<int> nums5 = {10};

    cout << "Test Case 5 Array: ";

    for(int x : nums5){
        cout << x << " ";
    }

    cout << endl;

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(nums5);

    cout << endl << endl;

    return 0;
}