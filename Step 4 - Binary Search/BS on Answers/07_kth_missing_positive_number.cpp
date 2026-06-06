// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

// Example 2:
// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k) low = mid+1;
        else high = mid-1;
    }
    return low + k;
}

int main(){
    vector<int> arr1 = {2,3,4,7,11};
    int k1 = 5;
    int ans1 = findKthPositive(arr1, k1);
    cout << "The " << k1 << "th missing positive number in [ ";
    for(int x : arr1){
        cout << x << " ";
    }
    cout << "] is " << ans1 << endl;

    vector<int> arr2 = {1,2,3,4};
    int k2 = 2;
    int ans2 = findKthPositive(arr2, k2);
    cout << "The " << k2 << "th missing positive number in [ ";
    for(int x : arr2){
        cout << x << " ";
    }
    cout << "] is " << ans2 << endl;

    vector<int> arr3 = {5,6,7,8,9};
    int k3 = 4;
    int ans3 = findKthPositive(arr3, k3);
    cout << "The " << k3 << "th missing positive number in [ ";
    for(int x : arr3){
        cout << x << " ";
    }
    cout << "] is " << ans3 << endl;
    return 0;
}