// Given an integer array nums. Return the number of inversions in the array.
// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// It indicates how close an array is to being sorted.
// A sorted array has an inversion count of 0.
// An array sorted in descending order has maximum inversion.

// Example 1
// Input: nums = [2, 3, 7, 1, 3, 5]
// Output: 5
// Explanation:
// The responsible indexes are:
// nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
// nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
// nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
// nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
// nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

// Example 2
// Input: nums = [-10, -5, 6, 11, 15, 17]
// Output: 0
// Explanation:
// nums is sorted, hence no inversions present.

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// long long int numberOfInversions(vector<int> nums) {
//     int n = nums.size();
//     long long cnt = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             if(nums[i] > nums[j]) cnt++;
//         }
//     }
//     return cnt;
// }

// Time Complexity: O(N^2)
// Space Complexity: O(1)

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;

    int cnt = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){        // left is smaller
            temp.push_back(arr[left]);
            left++;
        } 
        else{                               // right is smaller
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);        // 
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

long long int numberOfInversions(vector<int> &nums) {
    return mergeSort(nums, 0, nums.size());
}

int main(){
    vector<int> q = {5,3,2,4,1};
    int n = q.size()-1;
    cout<<"Array before sorting: [";
    for(auto i : q){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    long long count = numberOfInversions(q);
    cout<<"Array after sorting: [";
    for(auto i : q){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    cout<<"The number of Inversionas are: "<<count<<endl;
    return 0;
}