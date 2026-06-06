// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] 
// and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
// If it is impossible to make m bouquets return -1.

// Example 1:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. 
// x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

// Example 2:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. 
// We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

// Example 3:
// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. 
// We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.

#include<bits/stdc++.h>
using namespace std;

bool if_bouquets_possible(vector<int>& bloomDay, int m, int k, int day){
    int cnt = 0, no_of_bouquets = 0;
    for(int i = 0; i < bloomDay.size(); i++){
        // blooming possible
        if(bloomDay[i] <= day) cnt++;
        else{
            no_of_bouquets += cnt/k;
            cnt = 0;
        }
    }
    no_of_bouquets += cnt/k;
    if(no_of_bouquets >= m) return true;
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if((long long)m*k > bloomDay.size()) return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while(low <= high){
        int mid = low + (high - low)/2;
        if(if_bouquets_possible(bloomDay, m, k, mid) == true) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    int ans1 = minDays(bloomDay1, m1, k1);
    cout << "Minimum days for bloomDay = [ ";
    for(int day : bloomDay1){
        cout << day << " ";
    }
    cout << "]";
    cout << " is " << ans1 << " for " << m1 << " bouquets and " << k1 << " flowers per bouquet." << endl;


    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    int ans2 = minDays(bloomDay2, m2, k2);
    cout << "Minimum days for bloomDay = [ ";
    for(int day : bloomDay2){
        cout << day << " ";
    }
    cout << "]";
    cout << " is " << ans2 << " for " << m2 << " bouquets and " << k2 << " flowers per bouquet." << endl;


    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    int m3 = 2, k3 = 3;
    int ans3 = minDays(bloomDay3, m3, k3);
    cout << "Minimum days for bloomDay = [ ";
    for(int day : bloomDay3){
        cout << day << " ";
    }
    cout << "]";
    cout << " is " << ans3 << " for m " << m3 << " bouquets and k " << k3 << " flowers per bouquet." << endl;
    return 0;
}