// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1+n2;
    if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
    int low = 0, high = n1; // can take nothing (i.e. 0) or everything (i.e. n1) from smallest array.
    int left = (n1+n2+1)/2; // left side of the symmetry line.
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
        // symmetry for median condition
        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1,l2);
            return (double)(max(l1,l2) + min(r1, r2))/2.0;
        }
        else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}

int main(){
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    double ans1 = findMedianSortedArrays(nums1_1, nums2_1);
    cout << "Median of [ ";
    for(int x : nums1_1) cout << x << " ";
    cout << "] and [ ";
    for(int x : nums2_1) cout << x << " ";
    cout << "] is " << ans1 << endl;

    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    double ans2 = findMedianSortedArrays(nums1_2, nums2_2);
    cout << "Median of [ ";
    for(int x : nums1_2) cout << x << " ";
    cout << "] and [ ";
    for(int x : nums2_2) cout << x << " ";
    cout << "] is " << ans2 << endl;

    vector<int> nums1_3 = {0, 0};
    vector<int> nums2_3 = {0, 0};
    double ans3 = findMedianSortedArrays(nums1_3, nums2_3);
    cout << "Median of [ ";
    for(int x : nums1_3) cout << x << " ";
    cout << "] and [ ";
    for(int x : nums2_3) cout << x << " ";
    cout << "] is " << ans3 << endl;

    vector<int> nums1_4 = {};
    vector<int> nums2_4 = {1};
    double ans4 = findMedianSortedArrays(nums1_4, nums2_4);
    cout << "Median of [ ";
    for(int x : nums1_4) cout << x << " ";
    cout << "] and [ ";
    for(int x : nums2_4) cout << x << " ";
    cout << "] is " << ans4 << endl;

    vector<int> nums1_5 = {2, 5, 7, 9};
    vector<int> nums2_5 = {1, 3, 4, 6, 8};
    double ans5 = findMedianSortedArrays(nums1_5, nums2_5);
    cout << "Median of [ ";
    for(int x : nums1_5) cout << x << " ";
    cout << "] and [ ";
    for(int x : nums2_5) cout << x << " ";
    cout << "] is " << ans5 << endl;
    return 0;
}