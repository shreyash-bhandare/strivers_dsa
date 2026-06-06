// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
// The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. 
// Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include<bits/stdc++.h>
using namespace std;

int cal_total_hrs(vector<int>&piles, int h, int hourly_rate){
    int total_hrs = 0;
    for(int i = 0; i < piles.size(); i++){
        total_hrs += ceil((double)piles[i]/(double)hourly_rate);
        if(total_hrs > h) return INT_MAX;
    }
    return total_hrs;
}
int findMaxElement(vector<int>&piles){
    int maxElement = piles[0];
    for(int pile : piles){
        maxElement = max(maxElement, pile);
    }
    return maxElement;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = findMaxElement(piles);
    while(low <= high){
        int mid = low+(high-low)/2;
        if(cal_total_hrs(piles, h, mid) <= h) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    int ans1 = minEatingSpeed(piles1, h1);
    cout << "Minimum eating speed for ";
    cout<<"[ ";
    for(int pile : piles1){
        cout<<pile<<" ";
    }
    cout<<"]";
    cout<<" is " << ans1 <<" for "<<h1<<" hours."<< endl;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    int ans2 = minEatingSpeed(piles2, h2);
    cout << "Minimum eating speed for ";
    cout<<"[ ";
    for(int pile : piles2){
        cout<<pile<<" ";
    }
    cout<<"]";
    cout<<" is " << ans2 <<" for "<<h2<<" hours."<< endl;

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    int ans3 = minEatingSpeed(piles3, h3);
    cout << "Minimum eating speed for ";
    cout<<"[ ";
    for(int pile : piles3){
        cout<<pile<<" ";
    }
    cout<<"]";
    cout<<" is " << ans3 <<" for "<<h3<<" hours."<< endl;
    return 0;
}