// Given an array nums of size n, which denotes the positions of stalls, and an integer k, 
// which denotes the number of aggressive cows, assign stalls to k cows 
// such that the minimum distance between any two cows is the maximum possible. 
// Find the maximum possible minimum distance.

// Example 1
// Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]
// Output: 3
// Explanation:
// The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at 
// positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.
// In no manner can we increase the minimum distance beyond 3.

// Example 2
// Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]
// Output: 5
// Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at 
// positions [1, 6]. 

#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &nums, int cows, int dist){
    int cntCows = 1, last = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - last >= dist){
            cntCows++;
            last = nums[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &nums, int cows) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 1, high = nums[n-1] - nums[0];
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canWePlace(nums, cows, mid)) low = mid+1;
        else high = mid-1;
    }
    return high;
}

int main(){
    vector<int> stalls1 = {0, 3, 4, 7, 10, 9};
    int k1 = 4;
    int ans1 = aggressiveCows(stalls1, k1);
    cout << "Maximum minimum distance for stalls [ ";
    for(int stall : stalls1){
        cout << stall << " ";
    }
    cout << "] is " << ans1 << " for " << k1 << " cows." << endl;

    vector<int> stalls2 = {4, 2, 1, 3, 6};
    int k2 = 2;
    int ans2 = aggressiveCows(stalls2, k2);
    cout << "Maximum minimum distance for stalls [ ";
    for(int stall : stalls2){
        cout << stall << " ";
    }
    cout << "] is " << ans2 << " for " << k2 << " cows." << endl;

    vector<int> stalls3 = {1, 2, 4, 8, 9};
    int k3 = 3;
    int ans3 = aggressiveCows(stalls3, k3);
    cout << "Maximum minimum distance for stalls [ ";
    for(int stall : stalls3){
        cout << stall << " ";
    }
    cout << "] is " << ans3 << " for " << k3 << " cows." << endl;
    return 0;
}