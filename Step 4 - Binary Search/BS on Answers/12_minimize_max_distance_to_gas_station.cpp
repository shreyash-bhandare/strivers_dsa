// Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, 
// and an integer k, place k new gas stations on the X-axis.
// The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.
// Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.

// Find the minimum value of dist.

// Your answer will be accepted if it is within 1e-6 of the true value.

// Example 1
// Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10
// Output: 0.50000
// Explanation:
// One of the possible ways to place 10 gas stations is 
// [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10].
// Thus the maximum difference between adjacent gas stations is 0.5.
// Hence, the value of dist is 0.5.
// It can be shown that there is no possible way to add 10 gas stations in such a way that 
// the value of dist is lower than this.

// Example 2
// Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1
// Output: 1.00000
// Explanation:
// One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
// New Gas Station is at 11.
// Thus the maximum difference between adjacent gas stations is still 1.
// Hence, the value of dist is 1.
// It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this. 

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE : gives TLE
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();
//     vector<int> howMany(n-1, 0);
//     for(int gasStations = 1; gasStations <= k; gasStations++){
//         long double maxSection = -1;
//         int maxInd = -1;
//         for(int i = 0; i < n-1; i++ ){
//             long double diff = (arr[i+1] - arr[i]);
//             long double sectionLength = diff/(long double)(howMany[i]+1);
//             if(sectionLength > maxSection){
//                 maxSection = sectionLength;
//                 maxInd = i;
//             }
//         }
//         howMany[maxInd]++;
//     }
//     long double maxAns = -1;
//     for(int i = 0; i < n-1; i++){
//         long double diff = arr[i+1] - arr[i];
//         long double sectionLength = diff/(long double)(howMany[i]+1);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
// }

// Better Solution
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();
//     vector<int> howMany(n-1, 0);
//     priority_queue<pair<long double, int>>pq;
//     // takes log N time to insert. For N size, O(NlogN) time complexity
//     for(int i = 0; i < n-1; i++){
//         pq.push({arr[i+1]-arr[i], i});
//     }
//     // K log N
//     for(int gasStations = 1; gasStations <= k; gasStations++){
//         auto tp = pq.top();
//         pq.pop();
//         int secInd = tp.second;
//         howMany[secInd]++;
//         long double iniDiff = arr[secInd+1] - arr[secInd];
//         long double newSecLen = iniDiff/(long double)(howMany[secInd]+1);
//         pq.push({newSecLen, secInd});
//     }
//     return pq.top().first;
// }
// Time Complexity: O(NlogN) priority_queue N insertions, + O(KlogN) priority_queue k insertions.
// Space Complexity: O(n-1) priority_queue size;

int numberOfGasStationsRequired(long double dist, vector<int> &arr){
    int cnt = 0;
    for(int i = 1; i < arr.size(); i++){
        int numberInBetween = (arr[i] - arr[i-1])/dist;
        if(arr[i] - arr[i-1] == numberInBetween * dist) numberInBetween--;
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for(int i = 0; i < n-1; i++){
        high = max(high, (long double)arr[i+1]-arr[i]);
    }
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = low + (high - low)/2;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if(cnt > k) low = mid;
        else high = mid;
    }
    return high;
}

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 4;
    long double ans1 = minimiseMaxDistance(arr1, k1);
    cout << "Minimum maximum distance for stations [ ";
    for(int x : arr1){
        cout << x << " ";
    }
    cout << "] is " << ans1 << " after adding " << k1 << " gas stations." << endl;

    vector<int> arr2 = {1, 10};
    int k2 = 1;
    long double ans2 = minimiseMaxDistance(arr2, k2);
    cout << "Minimum maximum distance for stations [ ";
    for(int x : arr2){
        cout << x << " ";
    }
    cout << "] is " << ans2 << " after adding " << k2 << " gas stations." << endl;

    vector<int> arr3 = {1, 10};
    int k3 = 2;
    long double ans3 = minimiseMaxDistance(arr3, k3);
    cout << "Minimum maximum distance for stations [ ";
    for(int x : arr3){
        cout << x << " ";
    }
    cout << "] is " << ans3 << " after adding " << k3 << " gas stations." << endl;

    vector<int> arr4 = {1, 13, 17, 23};
    int k4 = 5;
    long double ans4 = minimiseMaxDistance(arr4, k4);
    cout << "Minimum maximum distance for stations [ ";
    for(int x : arr4){
        cout << x << " ";
    }
    cout << "] is " << ans4 << " after adding " << k4 << " gas stations." << endl;

    vector<int> arr5 = {3, 6, 12, 19};
    int k5 = 2;
    long double ans5 = minimiseMaxDistance(arr5, k5);
    cout << "Minimum maximum distance for stations [ ";
    for(int x : arr5){
        cout << x << " ";
    }
    cout << "] is " << ans5 << " after adding " << k5 << " gas stations." << endl;
    return 0;
}