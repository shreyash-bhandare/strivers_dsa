#include <bits/stdc++.h>
using namespace std;

// Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater 
// permutation of numbers.
// If such an arrangement is not possible, it must rearrange to the lowest possible order 
// (i.e., sorted in ascending order).

// Input: Arr[] = {1,3,2}
// Output: {2,1,3}
// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. 
// So, the next permutation just after {1,3,2} is {2,1,3}.

// Input : Arr[] = {3,2,1}
// Output: {1,2,3}
// Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. 
// So, we have to return the lowest permutation.

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index=-1; // (break point)
        // find index (i.e. break point)
        for(int i = n-2; i >= 0; i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        // if no break point found, return reverse of array as it is the last permutation.
        if(index==-1){
            reverse(nums.begin(), nums.end());
            for(int i : nums){
                cout << i << " ";
            }
            return;
        }
        
        // if break point found, do find next greater number than nums[index]
        for(int i = n-1; i > index; i--){
            if(nums[index] < nums[i]){
                swap(nums[index], nums[i]);
                break;
            }
        }
        
        // now reverse from index + 1 to end
        reverse(nums.begin() + index + 1, nums.end());
        for(int i : nums){
            cout<<i<<" ";
        }
    }

int main(){
    // Test Case 1
    vector<int> nums1 = {1,2,3};

    cout << "Test Case 1 Array: ";

    for(int x : nums1){
        cout << x << " ";
    }

    cout << endl;
    cout << "Next Permutation: ";
    nextPermutation(nums1);
    cout << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1,3,2};

    cout << "Test Case 2 Array: ";

    for(int x : nums2){
        cout << x << " ";
    }

    cout << endl;
    cout << "Next Permutation: ";
    nextPermutation(nums2);
    cout << endl << endl;

    // Test Case 3
    vector<int> nums3 = {3,2,1};

    cout << "Test Case 3 Array: ";

    for(int x : nums3){
        cout << x << " ";
    }

    cout << endl;
    cout << "Next Permutation: ";
    nextPermutation(nums3);
    cout << endl << endl;


    // Test Case 4
    vector<int> nums4 = {1,1,5};

    cout << "Test Case 4 Array: ";

    for(int x : nums4){
        cout << x << " ";
    }

    cout << endl;
    cout << "Next Permutation: ";
    nextPermutation(nums4);
    cout << endl << endl;


    // Test Case 5
    vector<int> nums5 = {2,3,1};

    cout << "Test Case 5 Array: ";

    for(int x : nums5){
        cout << x << " ";
    }

    cout << endl;
    cout << "Next Permutation: ";
    nextPermutation(nums5);
    cout << endl << endl;

    return 0;
}