// Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

// Example 1
// Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

// Example 2
// Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7
// Output: 256
// Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 
// 7th element of this array is 256.

#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1+n2;
    if(n1 > n2) return kthElement(nums2, nums1, k);
    int low = max(0, k-n2), high = min(k, n1); // can take nothing (i.e. 0) or everything (i.e. n1) from smallest array.
    int left = k; // left side of the symmetry line.
    while(low <= high){
        int mid1 = low + (high - low)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;     // in case l1 and l2 are not present
        // case when l1 will not be present:
        // when when we don't take any element from nums1 on left side.
        // case when l2 will not be present:
        // when when we take 'left' amount of elements from nums1 on left side.
        int r1 = INT_MAX, r2 = INT_MAX;     // in case r1 and r2 are not present.
        // case when r1 will not be present:
        // when when we take every element from nums1 on left side.
        // case when r2 will not be present:
        // when when we take 'left' amount of elements from nums2 on left side.
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2-1];
        // symmetry for kth element
        if(l1 <= r2 && l2 <= r1){
            return max(l1,l2);
        }
        else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}

int main(){
    vector<int> arr1_1 = {2, 3, 6, 7, 9};
    vector<int> arr2_1 = {1, 4, 8, 10};
    int k1 = 5;
    int ans1 = kthElement(arr1_1, arr2_1, k1);
    cout << "The " << k1 << "th element of [ ";
    for(int x : arr1_1) cout << x << " ";
    cout << "] and [ ";
    for(int x : arr2_1) cout << x << " ";
    cout << "] is " << ans1 << endl;

    vector<int> arr1_2 = {1, 2, 3, 4};
    vector<int> arr2_2 = {5, 6, 7, 8};
    int k2 = 6;
    int ans2 = kthElement(arr1_2, arr2_2, k2);
    cout << "The " << k2 << "th element of [ ";
    for(int x : arr1_2) cout << x << " ";
    cout << "] and [ ";
    for(int x : arr2_2) cout << x << " ";
    cout << "] is " << ans2 << endl;

    vector<int> arr1_3 = {1, 3, 5, 7};
    vector<int> arr2_3 = {2, 4, 6, 8, 9};
    int k3 = 9;
    int ans3 = kthElement(arr1_3, arr2_3, k3);
    cout << "The " << k3 << "th element of [ ";
    for(int x : arr1_3) cout << x << " ";
    cout << "] and [ ";
    for(int x : arr2_3) cout << x << " ";
    cout << "] is " << ans3 << endl;
    return 0;
}