// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Example 1:
// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

// Example 2:
// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

// BRUTE FORCE
// int reversePairs(vector<int>& nums) {
//     int n = nums.size();
//     int cnt = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             if(nums[i] > (long long)2*nums[j]) cnt++;
//         }
//     }
//     return cnt;
// }
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high){
    int right = mid + 1;
    int cnt = 0;
    for(int left = low; left <= mid; left++){
        while(right <= high && arr[left] > (long long)2 * arr[right]) right++;
        cnt += right - (mid + 1);
    }
    return cnt;
}
int mergeSort(vector<int>& arr, int low, int high) {
    int cnt = 0;
    if (low == high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversePairs(vector<int>& nums) { 
    int n = nums.size();
    int cnt = mergeSort(nums, 0, n-1);
    return cnt;
}

int main(){
    vector<int> q = {40,25,19,12,9,6,2};
    int n = q.size()-1;
    cout<<"Array before sorting: [";
    for(auto i : q){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    long long count = reversePairs(q);
    cout<<"Array after sorting: [";
    for(auto i : q){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    cout<<"The number of Inversionas are: "<<count<<endl;
    return 0;
}